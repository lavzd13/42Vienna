#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called." << std::endl;
	this->_type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat deconstructor called." << std::endl;
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

Cat&	Cat::operator= (const Cat& copy) {
	std::cout << "Cat copy operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "*meow meow*" << std::endl;
}

std::string	Cat::getType(void) const {
	return this->_type;
}
