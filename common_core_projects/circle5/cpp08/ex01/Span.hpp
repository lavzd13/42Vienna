#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		std::vector<unsigned int>	_storage;
		unsigned int		_limit;

	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span& operator=(const Span &copy);
		~Span();
		void				addNumber(unsigned int num);
		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;
		void				printElements() const;
		void				fill(int amount);
};
