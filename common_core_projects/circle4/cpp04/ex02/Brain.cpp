#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called." << std::endl;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "Pajo Pajo imam strasnu ideju";
	}
}

Brain::~Brain() {
	std::cout << "Brain deconstructor called." << std::endl;
	delete[] this->_ideas;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called." << std::endl;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i] + " copy";
}

Brain&	Brain::operator= (const Brain& copy) {
	std::cout << "Brain copy operator called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return *this;
}

std::string*	Brain::getIdeas(void) const {
	return this->_ideas;
}
