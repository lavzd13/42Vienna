#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <limits.h>

#define DIVIDING_ZERO

class RPN {
	private:
		std::stack<long int>	_rpn_stack;
		bool					perform_operation(char sign);
		int						check_compatibility(std::string &args);
	public:
		RPN();
		RPN(const RPN &copy);
		RPN& operator=(const RPN &copy);
		~RPN();
		void	start_rpn(std::string &args);
};

#endif
