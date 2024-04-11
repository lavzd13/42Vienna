#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	private:

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap& operator=(const FragTrap &copy);
		~FragTrap();
		void	highFiveGuys(void);
};
