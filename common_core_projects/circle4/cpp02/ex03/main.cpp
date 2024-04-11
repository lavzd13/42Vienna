#include "Point.hpp"

int	main(void) {
	bool check = bsp(Point (0, 0), Point (-4, 0), Point (-2, -4), Point (-1, -1.998));
	std::cout << CYAN << "A(0,0), B(-4,0), C(-2, -4), P(-1, -1.998)" << RESET << std::endl;
	check ? std::cout << GREEN << "True" << RESET << std::endl : std::cout << RED << "False" << RESET << std::endl;

	check = bsp(Point (1, 0), Point (2, 4), Point (1, 5), Point (1, 1));
	std::cout << CYAN << "A(1,0), B(2,4), C(1, 5), P(1, 1)" << RESET << std::endl;
	check ? std::cout << GREEN << "True" << RESET << std::endl : std::cout << RED << "False" << RESET << std::endl;

	check = bsp(Point (5, 0), Point (0, 0), Point (0, 5), Point (1, 1));
	std::cout << CYAN << "A(5,0), B(0,0), C(0, 5), P(1, 1)" << RESET<< std::endl;
	check ? std::cout << GREEN << "True" << RESET << std::endl : std::cout << RED << "False" << RESET << std::endl;

	check = bsp(Point (7, 0), Point (2, 3), Point (-3, -5), Point (1, 1));
	std::cout << CYAN << "A(7,0), B(2,3), C(-3, -5), P(1, 1)" << RESET << std::endl;
	check ? std::cout << GREEN << "True" << RESET << std::endl : std::cout << RED << "False" << RESET << std::endl;
}