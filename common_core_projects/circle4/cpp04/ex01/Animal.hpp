#pragma once

#include <iostream>

class Animal {
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy);
		virtual ~Animal();
		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;
};
