#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		std::string	_type;
		Brain*		_brain;
	public:
		Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &copy);
		~Dog();
		void		makeSound(void) const;
		std::string	getType(void) const;
		Brain*		getBrain(void) const;
		void		printIdeas(void) const;
};
