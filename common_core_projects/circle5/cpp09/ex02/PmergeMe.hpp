#pragma once

#include <cmath>
#include <ctime>
#include <deque>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

struct Element {
	long int	value;
	int			index;
	bool		inserted;
};

class PmergeMe {
	private:
		std::vector<Element>	_numbers;
		std::deque<Element>		_deqNumbers;
		std::vector<size_t>		_jacobSeq;
		std::deque<size_t>		_deqJacobSeq;

		std::vector<size_t>	_generateSequence(size_t n);
		std::deque<size_t>	_deqGenerateSequence(size_t n);
		bool				_checkArgs(std::string arg) const;
		void				_splitRecursively(std::vector<Element> &numbers, std::vector<std::vector<Element> > &mirrors);
		void				_deqSplitRecursively(std::deque<Element>& numbers, std::deque<std::deque<Element> >& mirrors);
		void				_mergeRecursively(std::vector<std::vector<Element> > &mirrors);
		void				_deqMergeRecursively(std::deque<std::deque<Element> > &mirrors);
		size_t				_binarySearch(const std::vector<Element> &mirror, long int value, size_t end);
		size_t				_deqBinarySearch(const std::deque<Element> &mirror, long int value, size_t end);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);
		~PmergeMe();
		int		start(int argc, char *argv[]);
};
