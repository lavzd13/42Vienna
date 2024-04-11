#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog deconstructor called." << std::endl;
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = copy;
}

Dog&	Dog::operator= (const Dog& copy) {
	std::cout << "Dog copy operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "*woof woof*" << std::endl;
}

std::string	Dog::getType(void) const {
	return this->_type;
}
