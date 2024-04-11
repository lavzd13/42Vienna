#pragma once

#include <iostream>

class Animal {
	protected:
		std::string	_type;
	public:
		Animal(const Animal &copy);
		Animal();
		Animal& operator=(const Animal &copy);
		virtual ~Animal() = 0;
		virtual void		makeSound(void) const = 0;
		virtual std::string	getType(void) const;
};
