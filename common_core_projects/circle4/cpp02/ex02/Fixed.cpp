#include "Fixed.hpp"

const int Fixed::_f_bits = 8;

Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed(const int num) {
	//std::cout << "Int constructor called" << std::endl;
	this->_fixed = num << Fixed::_f_bits;
}

Fixed::Fixed(const float num) {
	//std::cout << "Float constructor called" << std::endl;
	this->_fixed = (int)(roundf(num * 256));
}

Fixed::~Fixed() {
	//std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator= (const Fixed& copy) {
	//std::cout << "Copy assignment called" << std::endl;
	this->_fixed = copy.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
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

Fixed	Fixed::operator+(const Fixed& copy) const {
	Fixed res;
	res.setRawBits(_fixed + copy._fixed);
	return res;
}

Fixed	Fixed::operator-(const Fixed& copy) const {
	Fixed res;
	res.setRawBits(_fixed - copy._fixed);
	return res;
}

Fixed	Fixed::operator/(const Fixed& copy) const {
	if (copy._fixed == 0) {
		std::cout << "Error: can't divide by zero." << std::endl;
		return *this;
	}
	Fixed res;
	res.setRawBits(_fixed / copy._fixed * 256);
	return res;
}

Fixed	Fixed::operator*(const Fixed& copy) const {
	Fixed	res;
	res.setRawBits(_fixed * copy._fixed / 256);
	return res;
}

Fixed	Fixed::operator++() {
	this->_fixed++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--() {
	this->_fixed--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

bool	Fixed::operator<(const Fixed& copy) {
	return _fixed < copy._fixed;
}

bool	Fixed::operator<=(const Fixed& copy) {
	return _fixed <= copy._fixed;
}

bool	Fixed::operator>(const Fixed& copy) {
	return _fixed > copy._fixed;
}

bool	Fixed::operator>=(const Fixed& copy) {
	return _fixed >= copy._fixed;
}

bool	Fixed::operator==(const Fixed& copy) {
	return _fixed == copy._fixed;
}

bool	Fixed::operator!=(const Fixed& copy) {
	return _fixed != copy._fixed;
}

std::ostream&	operator<<(std::ostream &o, Fixed const &copy) {
	o << copy.toFloat();
	return o;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a._fixed < b._fixed)
		return a;
	else
		return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a._fixed > b._fixed)
		return a;
	else
		return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a._fixed < b._fixed)
		return a;
	else
		return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a._fixed > b._fixed)
		return a;
	else
		return b;
}
