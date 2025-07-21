#include "NOW.hpp"

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

void	PmergeMe::mergeRecursively(std::vector<std::vector<Element> > &mirrors) {
	if (mirrors.size() == 1)
		return;
}

void PmergeMe::giveIndexes(std::vector<Element>& numbers) {
	size_t	size = (numbers.size() % 2 != 0) ? numbers.size() - 1 : numbers.size();
	for (size_t i = 0, j = 0; i < size; i+=2) {
		numbers[i].index = j;
		numbers[i + 1].index = j;
		if (i % 2 == 0)
			j++;
	}
}

void PmergeMe::splitRecursively(std::vector<Element>& numbers) {
	static size_t	windowSize = 1;
	size_t	contSize = numbers.size() / windowSize;
	if (windowSize >= numbers.size())
		return;

	size_t	end = (windowSize * contSize) - ((contSize % 2 == 1) * windowSize);
	for (size_t i = 0; i < end; i += windowSize * 2) {
		++comparisons;
		if (numbers[i + windowSize - 1].value > numbers[i + (2 * windowSize) - 1].value) {
			for (size_t j = 0; j < windowSize; j++)
				std::swap(numbers[i + j], numbers[i + j + windowSize]);
		}
	}
	windowSize*=2;
	splitRecursively(numbers);
	windowSize/=2;

	std::vector<Element>	main;
	std::vector<Element>	pend;
	std::vector<Element>	left;
	Element					odd;

	odd.index = -1;
	odd.value = 0;

	// Push first two main values
	main.push_back(numbers[windowSize - 1]);
	main.push_back(numbers[(2 * windowSize) - 1]);

	for (size_t i = 2 * windowSize; i < end; i += 2 * windowSize) {
		pend.push_back(numbers[i + windowSize - 1]);
		main.push_back(numbers[i + (2 * windowSize) - 1]);
	}

	// Handle odd leftover
	if (contSize % 2 != 0)
		odd = numbers[end + windowSize - 1];

	// Append remaining values (leftovers)
	for (size_t i = end + ((contSize % 2 != 0) ? windowSize : 0); i < numbers.size(); ++i) {
		left.push_back(numbers[i]);
	}

	std::cout << "\nMAIN: \n";
	for (size_t i = 0; i < main.size(); i++) {
		std::cout << "VALUE: " << main[i].value << " --> " << "INDEX: " << main[i].index << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\nPEND: \n";
	for (size_t i = 0; i < pend.size(); i++) {
		std::cout << "VALUE: " << pend[i].value << " --> " << "INDEX: " << pend[i].index << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\nLEFT: \n";
	for (size_t i = 0; i < left.size(); i++) {
		std::cout << "VALUE: " << left[i].value << " --> " << "INDEX: " << left[i].index << std::endl;
	}
	std::cout << std::endl;
	// Perform Jacobsthal-based insert
	//if ((contSize % 2 != 0) || !pend.empty())
		//mergeRecursively(main, pend, odd, left, numbers, (contSize % 2 != 0), windowSize);
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

	giveIndexes(numbers);
	splitRecursively(numbers);
	mirrors.push_back(numbers);
	mergeRecursively(mirrors);
	//std::vector<long int>	res = fordJohnson(numbers);
	std::cout << "\nNUMBERS:\n";
	for (size_t i = 0; i < numbers.size(); ++i) {
		std::cout << "VALUE: " << numbers[i].value << " --> INDEX: " << numbers[i].index << " | ";
		std::cout << std::endl;
	}
	std::cout << "\nREAL DEAL: " << comparisons << std::endl;
	/* bool sorted = true;
	if (sorted)
		std::cout << "CORRECT" << std::endl; */
	return 0;
}
