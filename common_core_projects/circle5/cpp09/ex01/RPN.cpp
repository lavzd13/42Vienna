#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN& RPN::operator= (const RPN &copy) {
	_rpn_stack = copy._rpn_stack;
	return *this;
}

int		RPN::check_compatibility(std::string &args) {
	std::string	valid_chars = "0123456789+-*/ ";
	std::string	nums = "0123456789";
	std::string	opers = "+-*/";
	int			validity = 0;

	for (size_t i = 0; i < args.size(); i++) {
		if (valid_chars.find(args[i]) == std::string::npos)
			return 1;
		if (nums.find(args[i]) != std::string::npos) {
			validity++;
			if (args[i + 1] != ' ')
				return 1;
		}
		if (opers.find(args[i]) != std::string::npos)
			validity--;
		if (validity == 0)
			return 2;
	}
	if (validity != 1)
		return 2;
	return 0;
}

bool		RPN::perform_operation(char sign) {
	long int	first = _rpn_stack.top();

	_rpn_stack.pop();

	long int	second = _rpn_stack.top();

	_rpn_stack.pop();

	long int	res = 0;
	if (sign == '+') {
		res = second + first;
		if (res > INT_MAX || res < INT_MIN) {
			std::cerr << "Error: integer overflow" << std::endl;
			return false;
		}
		_rpn_stack.push(res);
		return true;
	}
	else if (sign == '-') {
		res = second - first;
		if (res < INT_MIN || res > INT_MAX) {
			std::cerr << "Error: integer overflow" << std::endl;
			return false;
		}
		_rpn_stack.push(res);
		return true;
	}
	else if (sign == '*') {
		res = second * first;
		if (res > INT_MAX || res < INT_MIN) {
			std::cerr << "Error: integer overflow" << std::endl;
			return false;
		}
		_rpn_stack.push(res);
		return true;
	}
	else if (sign == '/') {
		if (first != 0)
		res = second / first;
		else {
			std::cerr << "Error: dividing with zero" << std::endl;
			return false;
		}
		if (res > INT_MAX || res < INT_MIN) {
			std::cerr << "Error: integer overflow" << std::endl;
			return false;
		}
		_rpn_stack.push(res);
		return true;
	}
	return false;
}

void	RPN::start_rpn(std::string &args) {
	args.erase(0, args.find_first_not_of(" \t"));
	args.erase(args.find_last_not_of(" \t") + 1);

	if (check_compatibility(args) == 1) {
		std::cerr << "Error: invalid characters detected." << std::endl;
		return;
	}
	else if (check_compatibility(args) == 2) {
		std::cerr << "Error: invalid number of numbers or operands." << std::endl;
		return;
	}

	for (size_t i = 0; i < args.size(); i++) {
		if (std::isdigit(args[i])) {
			_rpn_stack.push(atoi(&args[i]));
		}
		if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/') {
			if (!perform_operation(args[i]))
				return;
		}
	}
	std::cout << _rpn_stack.top() << std::endl;
}
