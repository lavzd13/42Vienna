#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called." << std::endl;
	this->_type = "Cat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat deconstructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = copy;
}

WrongCat&	WrongCat::operator= (const WrongCat& copy) {
	std::cout << "WrongCat copy operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "*wrong meow*" << std::endl;
}

std::string	WrongCat::getType(void) const {
	return this->_type;
}
