#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		std::string	_type;
		Brain*		_brain;
	public:
		Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &copy);
		~Cat();
		void		makeSound(void) const;
		std::string	getType(void) const;
		Brain*		getBrain(void) const;
		void		printIdeas(void) const;
};
