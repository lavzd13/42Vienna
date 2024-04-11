#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << a * 5000 << std::endl;
	a = a * 5200;
	std::cout << a << std::endl;
	a--;
	a/0;
	if (a > b)
		std::cout << "a is bigger than b" << std::endl;
	else if (a < b)
		std::cout << "a is not bigger than b" << std::endl;
	else
		std::cout << "smth else" << std::endl;
	if (a == b)
		std::cout << "a is equal to b" << std::endl;
	else if (a != b)
		std::cout << "a is not equal to b" << std::endl;
	else
		std::cout << "smth else" << std::endl;
	std::cout << "Min: " << Fixed::min(a, b) << std::endl;
	std::cout << "Max: " << Fixed::max(a, b) << std::endl;
	return 0;
}