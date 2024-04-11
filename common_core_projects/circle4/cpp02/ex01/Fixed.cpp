#include "Fixed.hpp"

const int Fixed::_f_bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = num << Fixed::_f_bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = (int)(roundf(num * 256));
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator= (const Fixed& copy) {
	std::cout << "Copy assignment called" << std::endl;
	this->_fixed = copy.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixed = raw;
}

float	Fixed::toFloat(void) const {
	return (float)((float)this->_fixed / 256);
}

int	Fixed::toInt(void) const {
	return this->_fixed >> Fixed::_f_bits;
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}