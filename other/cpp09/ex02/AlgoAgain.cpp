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

std::vector<size_t> PmergeMe::generateSequence(size_t n) {
	std::vector<size_t>	JacobSequence;
	if (n <= 0)
		return JacobSequence;
	JacobSequence.push_back(1);
	if (n > 1)
		JacobSequence.push_back(3);
	for (size_t i = 2; i < n; i++)
		JacobSequence.push_back(JacobSequence[i - 1] + 2*JacobSequence[i - 2]);

	std::vector<size_t>	modifiedSeq;
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

void PmergeMe::splitRecursively(std::vector<Element>& numbers, std::vector<std::vector<Element> >& mirrors) {
	if (numbers.size() <= 1)
		return;

	std::vector<Element> newLower;
	std::vector<Element> newMain;
	std::vector<size_t> indexes;

	// Save the indexes after making pairs
	if (mirrors.size() == 1 && numbers.size() <= mirrors[0].size()) {
		for (size_t i = 0; i < numbers.size(); ++i) {
			numbers[i].index = i + 1;
			mirrors[0][i].index = i + 1;
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

size_t	PmergeMe::binarySearch(const std::vector<Element> &mirror, int index, long int value, size_t end) {
	size_t	left = 0;
	size_t	right = end;

	while (left < right) {
		size_t mid = left + ((right - left) / 2);

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

	mirrors[size - 1].insert(mirrors[size - 1].begin(), mirrors[size - 2][0]);
	insertIndexes.push_back(0);
	for (size_t i = 1; i < mirrors[size - 2].size(); i++) {
		size_t	position = binarySearch(mirrors[size - 1], mirrors[size - 2][i].index, mirrors[size - 2][i].value, mirrors[size - 1].size());
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
	std::vector<size_t>		inserted;

	std::cout << "\nSORTED: ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i].value << ", ";

	std::cout << "\nUNSORT: ";
	for (size_t i = 0; i < unsorted.size(); i++)
		std::cout << unsorted[i].value << ", ";
	std::cout << std::endl;
	std::vector<size_t>		sequence = generateSequence((sorted.size() + unsorted.size()) / 2);

	sorted.insert(sorted.begin(), unsorted.front());
	inserted.push_back(unsorted.front().index);
	unsorted.erase(unsorted.begin());

	for (size_t i = 1; i < sequence.size(); i++) {
		size_t	endSearch = sorted.size();
		Element	bigOne;
		for (size_t j = 0; j < sorted.size(); j++) {
			if (j == sequence[i]) {
				endSearch = j;
				bigOne = sorted[j];
				break;
			}
		}
		Element	insertElement;
		int	used = -1;
		for (size_t k = 0; k < unsorted.size(); k++) {
			if (unsorted[k].index == bigOne.index) {
				insertElement = unsorted[k];
				used = k;
				break;
			}
		}
		if (used == -1) {
			for (size_t	bz = 0; bz < sorted.size(); bz++) {
				bool	found = false;
				for (size_t prc = 0; prc < unsorted.size(); prc++) {
					if (sorted[bz].index == unsorted[prc].index) {
						insertElement = unsorted[prc];
						endSearch = bz;
						used = prc;
						found = true;
						break;
					}
				}
				if (found)
					break;
			}
		}
		std::cout << "\nJACOB: " << sequence[i] << " END SEARCH: " << endSearch << " SIZE: " << sorted.size() << " USED: " << used << std::endl;
		std::cout << "ELEMENT: " << insertElement.value << std::endl;
		if (used >= 0) {
			size_t	pos = binarySearch(sorted, insertElement.index, insertElement.value, endSearch);
			sorted.insert(sorted.begin() + pos, insertElement);
			unsorted.erase(unsorted.begin() + used);
		}
	}

	if (!unsorted.empty()) {
		size_t	pos = binarySearch(sorted, unsorted[0].index, unsorted[0].value, sorted.size());
		sorted.insert(sorted.begin() + pos, unsorted[0]);
		unsorted.erase(unsorted.begin());
	}

	mirrors[1] = sorted;

	std::cout << "\nUNSORTED: ";
	for (size_t i = 0; i < unsorted.size(); i++)
		std::cout << unsorted[i].value << ", ";
	std::cout << std::endl;
	std::cout << "\nJACOB: ";
	for (size_t i = 0; i < sequence.size(); i++)
		std::cout << sequence[i] << ", ";
	std::cout << std::endl;
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
	std::cout << "\nAFTER MERGE: \n";
	for (size_t i = 0; i < mirrors.size(); ++i) {
		for (size_t j = 0; j < mirrors[i].size(); j++) {
			// /std::cout << mirrors[i][j].value << ", ";
			std::cout << "VALUE: " << mirrors[i][j].value << " --> INDEX: " << mirrors[i][j].index << " | ";
		}
		std::cout << std::endl;
	}

	binaryInsert(mirrors);

	std::cout << "\nFINAL:\n";
	for (size_t j = 0; j < mirrors[1].size(); j++) {
		// /std::cout << mirrors[i][j].value << ", ";
		std::cout << "VALUE: " << mirrors[1][j].value << " --> INDEX: " << mirrors[1][j].index << std::endl;
	}
	std::cout << "\nSIZE OF SORTED: " << mirrors[1].size() << std::endl;
	std::cout << std::endl << comparisons << std::endl;
	bool sorted = true;

	for (size_t i = 0; i + 1 < mirrors[1].size(); i++) {
		if (mirrors[1][i].value > mirrors[1][i + 1].value || mirrors[1][i].value == mirrors[1][i + 1].value)
			sorted = false;
	}
	if (sorted)
		std::cout << "CORRECT" << std::endl;
	return 0;
}
