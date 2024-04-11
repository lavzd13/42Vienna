#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &copy);
		~Dog();
		void		makeSound(void) const;
		std::string	getType(void) const;
};
