#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	stray = 0;
	comparisons = 0;
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe& PmergeMe::operator= (const PmergeMe &copy) {
	comparisons = copy.comparisons;
	stray = copy.stray;
	numbers = copy.numbers;
	pairs = copy.pairs;
	return *this;
}

void PmergeMe::printNumbers() const {
	size_t	i;

	for (i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << ", ";
	std::cout << std::endl;

	/* for (i = 0; i < pairs.size() - 1; i++)
		std::cout << "{" << pairs[i].first << ", " << pairs[i].second << "}, ";
	std::cout << "{" << pairs[i].first << ", " << pairs[i].second << "} " << "stray: " << stray << std::endl; */
	std::cout << "Comparisons: " << comparisons << std::endl;
}

bool PmergeMe::checkArgs(std::string args) const {
	size_t	i = 0;
	if (args[0] == '+')
		i++;
	while (i < args.length()) {
		if (!isdigit(args[i]))
			return false;
		i++;
	}
	return true;
}

/* int PmergeMe::pushNumbers(int argc, char *argv[]) {
	for (int i = 1; i < argc; i+=2) {
		if (this->checkArgs(argv[i]) && atol(argv[i]) >= 0) {
			if (i + 1 < argc) {
				comparisons++;
				if (atol(argv[i]) > atol(argv[i + 1]))
					pairs.push_back(std::make_pair(atol(argv[i]), atol(argv[i + 1])));
				else
					pairs.push_back(std::make_pair(atol(argv[i + 1]), atol(argv[i])));
			}
			else
				stray = atol(argv[i]);
		}
		else {
			std::cerr << "Error: Please provide only valid postive integers." << std::endl;
			return 1;
		}
	}
	return 0;
}

std::vector<int> PmergeMe::extractPairsElements(int flag) {
	std::vector<int>	res;

	for (size_t i = 0; i < pairs.size(); i++) {
		if (flag == 1)
			res.push_back(pairs[i].first);
		else
			res.push_back(pairs[i].second);
	}
	return res;
} */

std::vector<int> PmergeMe::generateSequence(size_t n) {
	std::vector<int>	JacobSequence;
	if (n <= 0)
		return JacobSequence;
	JacobSequence.push_back(1);
	if (n > 1)
		JacobSequence.push_back(3);
	for (size_t i = 2; i < n; i++)
		JacobSequence.push_back(JacobSequence[i - 1] + 2*JacobSequence[i - 2]);

	std::vector<int>	modifiedSeq;
	modifiedSeq.push_back(1);
	for (size_t i = 0; i < JacobSequence.size(); i++) {
		int	curr = JacobSequence[i];
		while ((std::find(modifiedSeq.begin(), modifiedSeq.end(), curr) == modifiedSeq.end()) && modifiedSeq.size() < n) {
			modifiedSeq.push_back(curr);
			curr-=1;
		}
	}
	return modifiedSeq;
}

int	PmergeMe::binarySearch(const std::vector<long int>& nums, long int value, int end) {
	int	left = 0;
	int right = (end >= 0 && end <= static_cast<int>(nums.size())) ? end : nums.size();

	if (nums.size() <= 1)
		return left;

	while (left < right) {
		int mid = left + (right - left) / 2;

		comparisons++;
		if (value >= nums[mid])
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int g_count = 0;

std::vector<long int> PmergeMe::fordJohnson(std::vector<long int> &numbers) {
	if (numbers.size() <= 1)
		return numbers;
	std::vector<long int>	largeElements;
	std::vector<long int>	smallElements;
	bool					hasStray = false;
	long int				localStray;

	// ODVAJANJE ELEMENATA
	for (size_t i = 0; i < numbers.size(); i+=2) {
		if (i + 1 < numbers.size()) {
			comparisons++;
			if (numbers[i] > numbers[i + 1]) {
				largeElements.push_back(numbers[i]);
				smallElements.push_back(numbers[i + 1]);
			}
			else {
				largeElements.push_back(numbers[i + 1]);
				smallElements.push_back(numbers[i]);
			}
		}
		else {
			localStray = numbers[i];
			hasStray = true;
		}
	}

	// REKURZIJA
	std::vector<long int>	sortedLarge = fordJohnson(largeElements);
	std::vector<int> largePos(largeElements.size());

	for (size_t i = 0; i < sortedLarge.size(); ++i) {
		for (size_t j = 0; j < largeElements.size(); ++j) {
			if (sortedLarge[i] == largeElements[j]) {
				largePos[j] = i;
				break;
			}
		}
	}


	std::cout << "Pozicije: ";
	for (size_t i = 0; i < largePos.size(); i++)
		std::cout << largePos[i] << ", ";
	std::cout << std::endl;


	// PRAVLJENJE SEKVENCE
	std::vector<int>		JacobSequence = generateSequence(smallElements.size());
	std::vector<long int>	fullSorted = sortedLarge;

	// UBACIVANJE ELEMENATA
	std::vector<std::pair<long int, bool> > inserted(smallElements.size());

	for (size_t i = 0; i < inserted.size(); i++) {
		inserted[i].first = smallElements[i];
		inserted[i].second = false;
	}

	if (!JacobSequence.empty()) {
		long int firstValue = smallElements[JacobSequence[0] - 1];
		//std::vector<long int>::iterator insertIt = std::lower_bound(fullSorted.begin(), fullSorted.end(), firstValue);
		int temp = comparisons;
		int	pos = binarySearch(fullSorted, firstValue, fullSorted.size());
		std::cout << "DIFF in FIRST IF: " << comparisons - temp << " ++++\n";
		fullSorted.insert(fullSorted.begin() + pos, firstValue);
		inserted[JacobSequence[0] - 1].second = true;
	}

	for (size_t i = 1; i < JacobSequence.size(); i++) {
		int insertIndx = JacobSequence[i] - 1;
		if (insertIndx >= static_cast<int>(smallElements.size()))
			continue;

		long int value = smallElements[insertIndx];
		//std::vector<long int>::iterator insertIt = std::lower_bound(fullSorted.begin(), fullSorted.end(), value);
		int temp = comparisons;
		int	pos = binarySearch(fullSorted, value, largePos[insertIndx]);
		std::cout << "DIFF in main part: " << comparisons - temp << "----\n";
		fullSorted.insert(fullSorted.begin() + pos, value);
		inserted[insertIndx].second = true;
	}

	std::cout << std::endl;
	for (size_t i = 0; i < inserted.size(); ++i) {
		if (!inserted[i].second) {
			g_count++;
			long int value = smallElements[i];
			//std::vector<long int>::iterator insertIt = std::lower_bound(fullSorted.begin(), fullSorted.end(), value);
			int temp = comparisons;
			int	pos = binarySearch(fullSorted, value, largePos[i]);
			std::cout << "DIFF in insert part: " << comparisons - temp << "....";
			fullSorted.insert(fullSorted.begin() + pos, value);
		}
	}
	std::cout << std::endl;

	if (hasStray) {
		//std::vector<long int>::iterator insertIt = std::lower_bound(fullSorted.begin(), fullSorted.end(), localStray);
		int temp = comparisons;
		int	pos = binarySearch(fullSorted, localStray, fullSorted.size());
			std::cout << "DIFF in stray part: " << comparisons - temp << "....\n";
		fullSorted.insert(fullSorted.begin() + pos, localStray);
	}
	return fullSorted;
}

int PmergeMe::start(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Error: provide at least one argument." << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (this->checkArgs(argv[i]) && atol(argv[i]) >= 0) {
			numbers.push_back(atol(argv[i]));
		}
		else {
			std::cerr << "Error: Please provide only valid postive integers." << std::endl;
			return 1;
		}
	}
	std::vector<long int>	res = fordJohnson(numbers);
	printNumbers();
	std::cout << "Size of RES: " << res.size() << " Result: ";
	for (size_t i = 0; i < res.size(); i++)
		std::cout << res[i] << ", ";
	std::cout << std::endl;
	std::cout << "COUNT: " << g_count << std::endl;
	bool sorted = true;
	for (size_t i = 1; i < res.size(); ++i) {
		if (res[i-1] > res[i]) {
			sorted = false;
			break;
		}
	}
	if (sorted)
		std::cout << "CORRECT" << std::endl;
	return 0;
}
