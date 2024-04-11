#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal deconstructor called." << std::endl;
}

Animal::Animal(const Animal& copy) {
	*this = copy;
}

Animal&	Animal::operator= (const Animal& copy) {
	this->_type = copy._type;
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "Default animal sound" << std::endl;
}

std::string	Animal::getType(void) const {
	return this->_type;
}
