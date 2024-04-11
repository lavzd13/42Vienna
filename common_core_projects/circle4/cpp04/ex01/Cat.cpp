#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::~Cat() {
	std::cout << "Cat deconstructor called." << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->_brain = new Brain(*(copy.getBrain()));
	this->_type = copy.getType();
}

Cat&	Cat::operator= (const Cat& copy) {
	std::cout << "Cat copy operator called." << std::endl;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain;
	this->_type = copy._type;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "*meow meow*" << std::endl;
}

std::string	Cat::getType(void) const {
	return this->_type;
}

Brain*	Cat::getBrain(void) const {
	return this->_brain;
}

void	Cat::printIdeas(void) const {
	for (int i = 0; i < 100; i++) {
		std::cout << this->_brain->getIdeas()[i] << std::endl;
	}
}
