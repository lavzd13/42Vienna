#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe& PmergeMe::operator= (const PmergeMe &copy) {
	_numbers = copy._numbers;
	return *this;
}

bool	PmergeMe::_checkArgs(std::string args) const {
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

std::vector<size_t>	PmergeMe::_generateSequence(size_t n) {
	_jacobSeq.clear();
	std::vector<size_t>	JacobSequence;
	if (n <= 0) {
		_jacobSeq = JacobSequence;
		return JacobSequence;
	}
	JacobSequence.push_back(1);
	if (n > 1)
		JacobSequence.push_back(3);
	for (size_t i = 2; i < n; i++)
		JacobSequence.push_back(JacobSequence[i - 1] + 2*JacobSequence[i - 2]);
	_jacobSeq = JacobSequence;
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

std::deque<size_t>	PmergeMe::_deqGenerateSequence(size_t n) {
	_deqJacobSeq.clear();
	std::deque<size_t>	JacobSequence;
	if (n <= 0) {
		_deqJacobSeq = JacobSequence;
		return JacobSequence;
	}
	JacobSequence.push_back(1);
	if (n > 1)
		JacobSequence.push_back(3);
	for (size_t i = 2; i < n; i++)
		JacobSequence.push_back(JacobSequence[i - 1] + 2*JacobSequence[i - 2]);
	_deqJacobSeq = JacobSequence;
	std::deque<size_t>	modifiedSeq;
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

void	PmergeMe::_splitRecursively(std::vector<Element>& numbers, std::vector<std::vector<Element> >& mirrors) {

	if (mirrors.size() == 1) {
		for (size_t i = 0; i < numbers.size(); i++) {
			numbers[i].index = i + 1;
			mirrors[0][i].index = i + 1;
		}
	}

	if (numbers.size() <= 1) {
		mirrors.push_back(numbers);
		return;
	}
	std::vector<Element>	biggerElements;
	std::vector<Element>	smallerElements;
	std::vector<size_t>		bigIndexes;
	std::vector<size_t>		smallIndexes;

	for (size_t i = 0; i + 1 < numbers.size(); i += 2) {
		if (numbers[i].value > numbers[i + 1].value) {
			biggerElements.push_back(numbers[i]);
			smallerElements.push_back(numbers[i + 1]);
			bigIndexes.push_back(i);
			smallIndexes.push_back(i + 1);
		} else {
			biggerElements.push_back(numbers[i + 1]);
			smallerElements.push_back(numbers[i]);
			bigIndexes.push_back(i + 1);
			smallIndexes.push_back(i);
		}
	}

	if (numbers.size() % 2 != 0) {
		smallerElements.push_back(numbers.back());
		smallIndexes.push_back(numbers.size() - 1);
	}
	std::vector<std::vector<Element> >	newMirrors;
	std::vector<Element>				firstMirrorCopy;

	if (!mirrors.empty())
		firstMirrorCopy = mirrors[0];

	for (size_t i = 0; i < mirrors.size(); i++) {

		std::vector<Element>	biggerMirror;
		std::vector<Element>	smallerMirror;

		for (size_t j = 0, k = 0, l = 0; j < mirrors[i].size(); j++) {
			if (k < bigIndexes.size() && j == bigIndexes[k]) {
				biggerMirror.push_back(mirrors[i][j]);
				k++;
			} else if (l < smallIndexes.size() && j == smallIndexes[l]) {
				smallerMirror.push_back(mirrors[i][j]);
				l++;
			}
			else if (mirrors[i][j].index != -1) {
				biggerMirror.push_back(mirrors[i][j]);
			}
			else
				smallerMirror.push_back(mirrors[i][j]);
		}
		newMirrors.push_back(smallerMirror);
		newMirrors.push_back(biggerMirror);
	}


	newMirrors.push_back(smallerElements);

	mirrors = newMirrors;
	numbers = biggerElements;

	_splitRecursively(numbers, mirrors);
}

void	PmergeMe::_deqSplitRecursively(std::deque<Element>& numbers, std::deque<std::deque<Element> >& mirrors) {
	if (mirrors.size() == 1) {
		for (size_t i = 0; i < numbers.size(); i++) {
			numbers[i].index = i + 1;
			mirrors[0][i].index = i + 1;
		}
	}

	if (numbers.size() <= 1) {
		mirrors.push_back(numbers);
		return;
	}

	std::deque<Element>	biggerElements;
	std::deque<Element>	smallerElements;
	std::deque<size_t>	bigIndexes;
	std::deque<size_t>	smallIndexes;

	for (size_t i = 0; i + 1 < numbers.size(); i += 2) {
		if (numbers[i].value > numbers[i + 1].value) {
			biggerElements.push_back(numbers[i]);
			smallerElements.push_back(numbers[i + 1]);
			bigIndexes.push_back(i);
			smallIndexes.push_back(i + 1);
		} else {
			biggerElements.push_back(numbers[i + 1]);
			smallerElements.push_back(numbers[i]);
			bigIndexes.push_back(i + 1);
			smallIndexes.push_back(i);
		}
	}

	if (numbers.size() % 2 != 0) {
		smallerElements.push_back(numbers.back());
		smallIndexes.push_back(numbers.size() - 1);
	}
	std::deque<std::deque<Element> >	newMirrors;
	std::deque<Element>				firstMirrorCopy;

	if (!mirrors.empty())
		firstMirrorCopy = mirrors[0];

	for (size_t i = 0; i < mirrors.size(); i++) {

		std::deque<Element>	biggerMirror;
		std::deque<Element>	smallerMirror;

		for (size_t j = 0, k = 0, l = 0; j < mirrors[i].size(); j++) {
			if (k < bigIndexes.size() && j == bigIndexes[k]) {
				biggerMirror.push_back(mirrors[i][j]);
				k++;
			} else if (l < smallIndexes.size() && j == smallIndexes[l]) {
				smallerMirror.push_back(mirrors[i][j]);
				l++;
			}
			else if (mirrors[i][j].index != -1) {
				biggerMirror.push_back(mirrors[i][j]);
			}
			else
				smallerMirror.push_back(mirrors[i][j]);
		}
		newMirrors.push_back(smallerMirror);
		newMirrors.push_back(biggerMirror);
	}


	newMirrors.push_back(smallerElements);

	mirrors = newMirrors;
	numbers = biggerElements;


	_deqSplitRecursively(numbers, mirrors);
}

size_t	PmergeMe::_binarySearch(const std::vector<Element> &mirror, long int value, size_t end) {
	size_t	left = 0;
	size_t	right = end;

	while (left < right) {
		size_t mid = left + ((right - left) / 2);

		if (value >= mirror[mid].value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

size_t	PmergeMe::_deqBinarySearch(const std::deque<Element> &mirror, long int value, size_t end) {
	size_t	left = 0;
	size_t	right = end;

	while (left < right) {
		size_t mid = left + ((right - left) / 2);

		if (value >= mirror[mid].value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

void	PmergeMe::_mergeRecursively(std::vector<std::vector<Element> > &mirrors) {
	size_t	size = mirrors.size();

	Element	temp;
	temp.value = -1;
	temp.index = -3;
	temp.inserted = true;

	if (size <= 2) {
		std::vector<size_t>	sequence = _generateSequence(mirrors[0].size());
		mirrors[1].insert(mirrors[1].begin(), mirrors[0][0]);
		mirrors[0][0].inserted = true;
		mirrors[0][0].value = -1;
		mirrors[0].insert(mirrors[0].begin(), temp);
		for (size_t i = 1, k = 1; i < sequence.size(); i++) {
			if (sequence[i] - 1 > mirrors[0].size()) {
				for (size_t j = mirrors[0].size() - 1; j > _jacobSeq[k - 1] - 1; j--) {
					if (!mirrors[0][j].inserted) {
						size_t endSearch = mirrors[1].size();
						for (size_t l = 0; l < mirrors[1].size(); l++) {
							if (mirrors[0][j].index == mirrors[1][l].index)
								endSearch = l;
						}
						size_t	pos = _binarySearch(mirrors[1], mirrors[0][j].value, endSearch);
						mirrors[1].insert(mirrors[1].begin() + pos, mirrors[0][j]);
						mirrors[0][j].inserted = true;
						mirrors[0][j].value = -1;
					}
				}
			}
			if (sequence[i] - 1 < mirrors[0].size() && !mirrors[0][sequence[i] - 1].inserted) {
				size_t	endSearch = mirrors[1].size();
				Element	oneToGo = mirrors[0][sequence[i] - 1];
				for (size_t j = 0; j < mirrors[1].size(); j++) {
					if (oneToGo.index == mirrors[1][j].index)
						endSearch = j;
				}
				size_t	pos = _binarySearch(mirrors[1], oneToGo.value, endSearch);
				mirrors[1].insert(mirrors[1].begin() + pos, oneToGo);
				mirrors[0][sequence[i] - 1].inserted = true;
				mirrors[0][sequence[i] - 1].value = -1;
			}
			if (sequence[i] == _jacobSeq[k])
				k++;
		}
		for (size_t i = 0; i < mirrors[0].size(); i++) {
			size_t	endSearch = mirrors[1].size();
			Element	oneToGo = mirrors[0][i];
			for (size_t j = 0; j < mirrors[1].size(); j++) {
				if (oneToGo.index == mirrors[1][j].index)
					endSearch = j;
			}
			if (!oneToGo.inserted) {
				size_t	pos = _binarySearch(mirrors[1], oneToGo.value, endSearch);
				mirrors[1].insert(mirrors[1].begin() + pos, oneToGo);
				mirrors[0][i].inserted = true;
				mirrors[0][i].value = -1;
			}
		}
		return;
	}

	std::vector<std::vector<Element> >	sortedMirror;

	for (size_t i = 0; i < mirrors.size(); i+=2) {
		mirrors[i + 1].insert(mirrors[i + 1].begin(), mirrors[i][0]);
		mirrors[i][0].value = -1;
		mirrors[i][0].index = -3;
		mirrors[i][0].inserted = true;
		mirrors[i].insert(mirrors[i].begin(), temp);
	}

	std::vector<size_t>	sequence = _generateSequence(mirrors[size - 2].size());

	for (size_t	i = 1, k = 1, track = 0; i < sequence.size(); i++) {
		if (sequence[i] - 1 > mirrors[size - 2].size()) {
			for (size_t j = mirrors[size - 2].size() - 1; j > _jacobSeq[k - 1] - 1; j--) {
				if (!mirrors[size - 2][j].inserted) {
					size_t	pos = _binarySearch(mirrors[size - 1], mirrors[size - 2][j].value, mirrors[size - 1].size());
					mirrors[size - 1].insert(mirrors[size - 1].begin() + pos, mirrors[size - 2][j]);
					mirrors[size - 2][j].inserted = true;
					for (size_t l = 0; l < mirrors.size() - 2; l+=2) {
						if (!mirrors[l][j].inserted && j < mirrors[l].size()) {
							mirrors[l + 1].insert(mirrors[l + 1].begin() + pos, mirrors[l][j]);
							mirrors[l][j].inserted = true;
						}
					}
				}

			}
		}
		if (sequence[i] - 1 < mirrors[size - 2].size() && !mirrors[size - 2][sequence[i] - 1].inserted) {
			size_t upperBound = sequence[i] + track - 1;
			if (upperBound >= mirrors[size - 1].size()) {
				upperBound = mirrors[size - 1].size();
			}
			size_t	pos = _binarySearch(mirrors[size - 1], mirrors[size - 2][sequence[i] - 1].value, upperBound);
			mirrors[size - 1].insert(mirrors[size - 1].begin() + pos, mirrors[size - 2][sequence[i] - 1]);
			mirrors[size - 2][sequence[i] - 1].inserted = true;
			track++;
			for (size_t j = 0; j < mirrors.size() - 2; j+=2) {
				if (!mirrors[j][sequence[i] - 1].inserted && sequence[i] - 1 < mirrors[j].size()) {
					mirrors[j + 1].insert(mirrors[j + 1].begin() + pos, mirrors[j][sequence[i] - 1]);
					mirrors[j][sequence[i] - 1].inserted = true;
				}
			}
		}
		if (sequence[i] == _jacobSeq[k])
			k++;
	}

	for (size_t i = 0; i < mirrors[size - 2].size(); i++) {
		if (!mirrors[size - 2][i].inserted) {
			size_t	pos = _binarySearch(mirrors[size - 1], mirrors[size - 2][i].value, mirrors[size - 1].size());
			mirrors[size - 1].insert(mirrors[size - 1].begin() + pos, mirrors[size - 2][i]);
			mirrors[size - 2][i].inserted = true;
			for (size_t j = 0; j < mirrors.size() - 2; j+=2) {
				if (!mirrors[j][i].inserted && i < mirrors[j].size()) {
					mirrors[j + 1].insert(mirrors[j + 1].begin() + pos, mirrors[j][i]);
					mirrors[j][i].inserted = true;
				}
			}
		}
	}

	for (size_t i = 0; i < mirrors.size() - 2; i+=2) {
		for (size_t j = 0; j < mirrors[i].size(); j++) {
			if (!mirrors[i][j].inserted)
				mirrors[i + 1].push_back(mirrors[i][j]);
		}
	}

	for (size_t i = 0; i < mirrors.size(); i+=2)
		sortedMirror.push_back(mirrors[i + 1]);

	mirrors = sortedMirror;
	for (size_t i = 0; i < sortedMirror.size(); i++) {
		for (size_t j = 0; j < sortedMirror[i].size(); j++)
			sortedMirror[i][j].inserted = false;
	}
	_mergeRecursively(mirrors);
}

void	PmergeMe::_deqMergeRecursively(std::deque<std::deque<Element> > &mirrors) {
	size_t	size = mirrors.size();

	Element	temp;
	temp.value = -1;
	temp.index = -3;
	temp.inserted = true;

	if (size <= 2) {
		std::deque<size_t>	sequence = _deqGenerateSequence(mirrors[0].size());
		mirrors[1].insert(mirrors[1].begin(), mirrors[0][0]);
		mirrors[0][0].inserted = true;
		mirrors[0][0].value = -1;
		mirrors[0].insert(mirrors[0].begin(), temp);
		for (size_t i = 1, k = 1; i < sequence.size(); i++) {
			if (sequence[i] - 1 > mirrors[0].size()) {
				for (size_t j = mirrors[0].size() - 1; j > _deqJacobSeq[k - 1] - 1; j--) {
					if (!mirrors[0][j].inserted) {
						size_t endSearch = mirrors[1].size();
						for (size_t l = 0; l < mirrors[1].size(); l++) {
							if (mirrors[0][j].index == mirrors[1][l].index)
								endSearch = l;
						}
						size_t	pos = _deqBinarySearch(mirrors[1], mirrors[0][j].value, endSearch);
						mirrors[1].insert(mirrors[1].begin() + pos, mirrors[0][j]);
						mirrors[0][j].inserted = true;
						mirrors[0][j].value = -1;
					}
				}
			}
			if (sequence[i] - 1 < mirrors[0].size() && !mirrors[0][sequence[i] - 1].inserted) {
				size_t	endSearch = mirrors[1].size();
				Element	oneToGo = mirrors[0][sequence[i] - 1];
				for (size_t j = 0; j < mirrors[1].size(); j++) {
					if (oneToGo.index == mirrors[1][j].index)
						endSearch = j;
				}
				size_t	pos = _deqBinarySearch(mirrors[1], oneToGo.value, endSearch);
				mirrors[1].insert(mirrors[1].begin() + pos, oneToGo);
				mirrors[0][sequence[i] - 1].inserted = true;
				mirrors[0][sequence[i] - 1].value = -1;
			}
			if (sequence[i] == _deqJacobSeq[k])
				k++;
		}
		for (size_t i = 0; i < mirrors[0].size(); i++) {
			size_t	endSearch = mirrors[1].size();
			Element	oneToGo = mirrors[0][i];
			for (size_t j = 0; j < mirrors[1].size(); j++) {
				if (oneToGo.index == mirrors[1][j].index)
					endSearch = j;
			}
			if (!oneToGo.inserted) {
				size_t	pos = _deqBinarySearch(mirrors[1], oneToGo.value, endSearch);
				mirrors[1].insert(mirrors[1].begin() + pos, oneToGo);
				mirrors[0][i].inserted = true;
				mirrors[0][i].value = -1;
			}
		}
		return;
	}

	std::deque<std::deque<Element> >	sortedMirror;

	for (size_t i = 0; i < mirrors.size(); i+=2) {
		mirrors[i + 1].insert(mirrors[i + 1].begin(), mirrors[i][0]);
		mirrors[i][0].value = -1;
		mirrors[i][0].index = -3;
		mirrors[i][0].inserted = true;
		mirrors[i].insert(mirrors[i].begin(), temp);
	}

	std::deque<size_t>	sequence = _deqGenerateSequence(mirrors[size - 2].size());

	for (size_t	i = 1, k = 1, track = 0; i < sequence.size(); i++) {
		if (sequence[i] - 1 > mirrors[size - 2].size()) {
			for (size_t j = mirrors[size - 2].size() - 1; j > _deqJacobSeq[k - 1] - 1; j--) {
				if (!mirrors[size - 2][j].inserted) {
					size_t	pos = _deqBinarySearch(mirrors[size - 1], mirrors[size - 2][j].value, mirrors[size - 1].size());
					mirrors[size - 1].insert(mirrors[size - 1].begin() + pos, mirrors[size - 2][j]);
					mirrors[size - 2][j].inserted = true;
					for (size_t l = 0; l < mirrors.size() - 2; l+=2) {
						if (!mirrors[l][j].inserted && j < mirrors[l].size()) {
							mirrors[l + 1].insert(mirrors[l + 1].begin() + pos, mirrors[l][j]);
							mirrors[l][j].inserted = true;
						}
					}
				}

			}
		}
		if (sequence[i] - 1 < mirrors[size - 2].size() && !mirrors[size - 2][sequence[i] - 1].inserted) {
			size_t upperBound = sequence[i] + track - 1;
			if (upperBound >= mirrors[size - 1].size()) {
				upperBound = mirrors[size - 1].size();
			}
			size_t	pos = _deqBinarySearch(mirrors[size - 1], mirrors[size - 2][sequence[i] - 1].value, upperBound);
			mirrors[size - 1].insert(mirrors[size - 1].begin() + pos, mirrors[size - 2][sequence[i] - 1]);
			mirrors[size - 2][sequence[i] - 1].inserted = true;
			track++;
			for (size_t j = 0; j < mirrors.size() - 2; j+=2) {
				if (!mirrors[j][sequence[i] - 1].inserted && sequence[i] - 1 < mirrors[j].size()) {
					mirrors[j + 1].insert(mirrors[j + 1].begin() + pos, mirrors[j][sequence[i] - 1]);
					mirrors[j][sequence[i] - 1].inserted = true;
				}
			}
		}
		if (sequence[i] == _deqJacobSeq[k])
			k++;
	}

	for (size_t i = 0; i < mirrors[size - 2].size(); i++) {
		if (!mirrors[size - 2][i].inserted) {
			size_t	pos = _deqBinarySearch(mirrors[size - 1], mirrors[size - 2][i].value, mirrors[size - 1].size());
			mirrors[size - 1].insert(mirrors[size - 1].begin() + pos, mirrors[size - 2][i]);
			mirrors[size - 2][i].inserted = true;
			for (size_t j = 0; j < mirrors.size() - 2; j+=2) {
				if (!mirrors[j][i].inserted && i < mirrors[j].size()) {
					mirrors[j + 1].insert(mirrors[j + 1].begin() + pos, mirrors[j][i]);
					mirrors[j][i].inserted = true;
				}
			}
		}
	}

	for (size_t i = 0; i < mirrors.size() - 2; i+=2) {
		for (size_t j = 0; j < mirrors[i].size(); j++) {
			if (!mirrors[i][j].inserted)
				mirrors[i + 1].push_back(mirrors[i][j]);
		}
	}

	for (size_t i = 0; i < mirrors.size(); i+=2)
		sortedMirror.push_back(mirrors[i + 1]);

	mirrors = sortedMirror;
	for (size_t i = 0; i < sortedMirror.size(); i++) {
		for (size_t j = 0; j < sortedMirror[i].size(); j++)
			sortedMirror[i][j].inserted = false;
	}
	_deqMergeRecursively(mirrors);
}

int	PmergeMe::start(int argc, char *argv[]) {
	if (argc < 3) {
		std::cerr << "Error: provide at least two arguments." << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (_checkArgs(argv[i]) && atol(argv[i]) >= 0) {
			Element	number;
			number.value = atol(argv[i]);
			number.index = -1;
			number.inserted = false;
			_numbers.push_back(number);
			_deqNumbers.push_back(number);
		}
		else {
			std::cerr << "Error: Please provide only valid postive integers." << std::endl;
			return 1;
		}
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i].value << " ";
	std::cout << std::endl;

	std::vector<std::vector<Element> >	vectorMirrors;
	std::deque<std::deque<Element> >	dequeMirrors;

	timeval	start, finish;

	gettimeofday(&start, NULL);

	long vecSeconds = 0;
	long vecMicroseconds = 0;
	long vecTotalMicroseconds = 0;

	_splitRecursively(_numbers, vectorMirrors);
	_mergeRecursively(vectorMirrors);

	gettimeofday(&finish, NULL);

	vecSeconds = finish.tv_sec - start.tv_sec;
	vecMicroseconds = finish.tv_usec - start.tv_usec;
	vecTotalMicroseconds = vecSeconds * 1000000 + vecMicroseconds;

	gettimeofday(&start, NULL);

	long deqSeconds = 0;
	long deqMicroseconds = 0;
	long deqTotalMicroseconds = 0;

	_deqSplitRecursively(_deqNumbers, dequeMirrors);
	_deqMergeRecursively(dequeMirrors);

	gettimeofday(&finish, NULL);

	deqSeconds = finish.tv_sec - start.tv_sec;
	deqMicroseconds = finish.tv_usec - start.tv_usec;
	deqTotalMicroseconds = deqSeconds * 1000000 + deqMicroseconds;


	bool	sorted = true;
	for (size_t i = 0; i + 1 < vectorMirrors[1].size(); i++) {
		if (vectorMirrors[1][i].value > vectorMirrors[1][i + 1].value)
			sorted = false;
		if (dequeMirrors[1][i].value > dequeMirrors[1][i + 1].value)
			sorted = false;
	}
	std::cout << "After: ";
	for (size_t i = 0; i < vectorMirrors[1].size(); i++) {
		std::cout << vectorMirrors[1][i].value << " ";
	}
	std::cout << std::endl;

	if (sorted) {
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vecTotalMicroseconds << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << deqTotalMicroseconds << " us" << std::endl;
	}
	return 0;
}
