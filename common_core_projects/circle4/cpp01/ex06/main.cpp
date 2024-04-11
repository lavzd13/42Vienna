#include "Harl.hpp"
#include <string>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Invalid number of arguments." << std::endl;
		return (1);
	}
	Harl	test;
	test.print(argv[1]);
}