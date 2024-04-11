#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::~Dog() {
	std::cout << "Dog deconstructor called." << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called." << std::endl;
	this->_brain = new Brain(*(copy.getBrain()));
	this->_type = copy.getType();
}

Dog&	Dog::operator= (const Dog& copy) {
	std::cout << "Dog copy operator called." << std::endl;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain;
	this->_type = copy._type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "*woof woof*" << std::endl;
}

std::string	Dog::getType(void) const {
	return this->_type;
}

Brain*	Dog::getBrain(void) const {
	return this->_brain;
}

void	Dog::printIdeas(void) const {
	for (int i = 0; i < 100; i++) {
		std::cout << this->_brain->getIdeas()[i] << std::endl;
	}
}
