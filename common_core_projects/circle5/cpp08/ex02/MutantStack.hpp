#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>

class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>() : std::stack<T>() {};
		MutantStack(const MutantStack<T> &copy): std::stack<T>(copy) {};
		MutantStack<T>& operator=(const MutantStack<T> &copy) {
			if (this != copy) {
				std::stack<T>::operator=(copy);
			}
			return *this;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return std::stack<T>::c.begin(); }
		const_iterator end() const { return std::stack<T>::c.end(); }

		void	iter() const {
			typename MutantStack<T>::const_iterator	start = this->begin();
			typename MutantStack<T>::const_iterator	end = this->end();
			while (start != end) {
				std::cout << *start << std::endl;
				++start;
			}
		};
};
