#pragma once

#include <deque>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

struct Element {
	long int	value;
	int			index;
};

class PmergeMe {
	private:
		long int							stray;
		std::vector<std::pair<int, int> >	pairs;
		std::vector<Element>				numbers;
		int									comparisons;

		std::vector<size_t> 		generateSequence(size_t n);
		std::vector<int>		extractPairsElements(int flag);
		bool					checkArgs(std::string arg) const;
		std::pair<int, int>		createPairs(int pair1, int pair2);
		void					splitRecursively(std::vector<Element> &numbers, std::vector<std::vector<Element> > &mirrors);
		void					mergeRecursively(std::vector<std::vector<Element> > &mirrors);
		std::vector<long int>	fordJohnson(std::vector<long int> &numbers);
		size_t					binarySearch(const std::vector<Element> &mirror, int index, long int value, size_t end);
		void					smartMerge(std::vector<Element>& result, const std::vector< std::vector<Element> >& mirrors);
		void					binaryInsert(std::vector<std::vector<Element> > &mirrors);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);
		~PmergeMe();
		void	printNumbers() const;
		int		start(int argc, char *argv[]);
		int		pushNumbers(int argc, char *argv[]);
};
