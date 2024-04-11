#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal deconstructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator= (const WrongAnimal& copy) {
	this->_type = copy._type;
	return *this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Default WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return this->_type;
}
