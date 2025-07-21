#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid number of arguments." << std::endl << "Usage: ./rpn \"args...\"" << std::endl;;
		return 1;
	}

	RPN rpn;
	std::string	temp = argv[1];

	rpn.start_rpn(temp);
}
