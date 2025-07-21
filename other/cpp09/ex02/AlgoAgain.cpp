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

// IMACU DVE REKURZIVNE FUNKCIJE JEDNA CE DA RAZDVAJA ELEMENTE DOK NE DOBIJEM SAMO JEDAN NAJVECI
// DRUGA CE DA RADI MERGE INSERT REKURZIVNO
// JOS UVEK NEMAM IDEJU KAKO CE RADITI MERGE INSERT REKURZIVNO ALI CEMO DA RESIMO

void PmergeMe::splitRecursively(std::vector<Element>& numbers, std::vector<std::vector<Element> >& mirrors) {
	if (numbers.size() <= 1)
		return;

	std::vector<Element> newLower;
	std::vector<Element> newMain;
	std::vector<size_t> indexes;

	// Save the indexes after making pairs
	if (mirrors.size() == 1 && numbers.size() <= mirrors[0].size()) {
		for (size_t i = 0; i < numbers.size(); ++i) {
			numbers[i].index = i;
			mirrors[0][i].index = i;
		}
	}

	// Split main container into bigger and smaller elements
	for (size_t i = 0; i + 1 < numbers.size(); i += 2) {
		++comparisons;
		// Save the indexes of the smaller elements so that we can later copy actions
		if (numbers[i].value > numbers[i + 1].value) {
			newMain.push_back(numbers[i]);
			newLower.push_back(numbers[i + 1]);
			indexes.push_back(i);
		} else {
			newMain.push_back(numbers[i + 1]);
			newLower.push_back(numbers[i]);
			indexes.push_back(i + 1);
		}
	}

	// Save the copy of first mirror for later insertion of stray
	std::vector<Element> firstMirrorCopy;
	if (!mirrors.empty())
		firstMirrorCopy = mirrors[0];

	// Creating new mirrors and splitting the current one, just copying the actions from main container
	std::vector< std::vector<Element> > newMirrors;

	for (size_t i = 0; i < mirrors.size(); ++i) {
		std::vector<Element> largerMirror;
		std::vector<Element> smallerMirror;

		for (size_t j = 0, k = 0; j < mirrors[i].size(); j++) {
			if (j == indexes[k]) {
				smallerMirror.push_back(mirrors[i][j]);
				k++;
			}
			else
				largerMirror.push_back(mirrors[i][j]);
		}

		// Push both mirrors to newMirrors
		newMirrors.push_back(largerMirror);
		newMirrors.push_back(smallerMirror);
	}

	// Setting the new values and putting stray at the last vector in mirrors

	if (!firstMirrorCopy.empty() && firstMirrorCopy.size() % 2 != 0) {
		if (!mirrors.empty())
			mirrors[0].push_back(firstMirrorCopy.back());
	}
	mirrors = newMirrors;

	if (numbers.size() % 2 == 1) {
		newLower.push_back(numbers.back());
	}

	numbers = newMain;
	mirrors.push_back(newLower);

	// Recursion
	splitRecursively(numbers, mirrors);
}

size_t jacobsthal(size_t n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	size_t a = 0, b = 1, c = 0;
	for (size_t i = 2; i <= n; ++i) {
		c = b + 2 * a;
		a = b;
		b = c;
	}
	return b;
}

size_t	PmergeMe::binarySearch(const std::vector<Element> &mirror, int index, long int value) {
	size_t	left = 0;
	size_t	right = mirror.size();

	while (left < right) {
		int mid = left + ((right - left) / 2);
		comparisons++;
		if (value >= mirror[mid].value)
			left = mid + 1;
		else
			right = mid;
	}
	(void)index;
	return left;
}


void	PmergeMe::mergeRecursively(std::vector<std::vector<Element> > &mirrors) {
	std::vector<std::vector<Element> >	sortedMirror;
	std::vector<size_t>					insertIndexes;
	size_t								size = mirrors.size();

	if (size == 2)
		return;

	for (size_t i = 0; i < mirrors[size - 2].size(); i++) {
		size_t	position = binarySearch(mirrors[size - 1], mirrors[size - 2][i].index, mirrors[size - 2][i].value);
		mirrors[size - 1].insert(mirrors[size - 1].begin() + position, mirrors[size - 2][i]);
		insertIndexes.push_back(position);
	}

	for (size_t i = 0; i < size - 2; i+=2) {
		for (size_t j = 0, k = 0; j < mirrors[i].size(); j++) {
			if (k < insertIndexes.size()) {
				mirrors[i + 1].insert(mirrors[i + 1].begin() + insertIndexes[k], mirrors[i][j]);
				k++;
			}
			else
				mirrors[i + 1].push_back(mirrors[i][j]);
		}
		sortedMirror.push_back(mirrors[i + 1]);
	}
	sortedMirror.push_back(mirrors[size - 1]);

	mirrors = sortedMirror;

	mergeRecursively(mirrors);
}

void	PmergeMe::binaryInsert(std::vector<std::vector<Element> > &mirrors) {
	std::vector<Element>	sorted = mirrors[1];
	std::vector<Element>	unsorted = mirrors[0];

	std::vector<int>		sequence = generateSequence((mirrors[1].size() + mirrors[0].size()) / 2);

	//sorted.insert(sorted.begin(), unsorted.front());

	for (size_t i = 0; i < sequence.size(); i++) {
		size_t pos = binarySearch(sorted, i, unsorted[sequence[i]].value);
		sorted.insert(sorted.begin() + pos, unsorted[sequence[i]]);
		unsorted.erase(unsorted.begin() + sequence[i]);
	}
	mirrors[1] = sorted;

	std::cout << "\nJACOB: ";
	for (size_t i = 0; i < sequence.size(); i++)
		std::cout << sequence[i] << ", ";
	std::cout << std::endl;
	return;
}

int PmergeMe::start(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Error: provide at least one argument." << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (this->checkArgs(argv[i]) && atol(argv[i]) >= 0) {
			Element	number;
			number.value = atol(argv[i]);
			number.index = -1;
			numbers.push_back(number);
		}
		else {
			std::cerr << "Error: Please provide only valid postive integers." << std::endl;
			return 1;
		}
	}
	std::cout << "\nOG ARRAY: ";
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i].value << ", ";
	std::cout << std::endl;
	std::vector<std::vector<Element> >	mirrors;

	splitRecursively(numbers, mirrors);
	mirrors.push_back(numbers);

	std::cout << "\nMIRRORS OG:\n";
	for (size_t i = 0; i < mirrors.size(); ++i) {
		for (size_t j = 0; j < mirrors[i].size(); j++) {
			// /std::cout << mirrors[i][j].value << ", ";
			std::cout << "VALUE: " << mirrors[i][j].value << " --> INDEX: " << mirrors[i][j].index << " | ";
		}
		std::cout << std::endl;
	}

	mergeRecursively(mirrors);
	binaryInsert(mirrors);

	std::cout << "\nMIRRORS:\n";
	for (size_t i = 0; i < mirrors.size(); ++i) {
		for (size_t j = 0; j < mirrors[i].size(); j++) {
			// /std::cout << mirrors[i][j].value << ", ";
			std::cout << "VALUE: " << mirrors[i][j].value << " --> INDEX: " << mirrors[i][j].index << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "\nREAL DEAL: " << comparisons << std::endl;
	/* bool sorted = true;
	if (sorted)
		std::cout << "CORRECT" << std::endl; */
	return 0;
}
