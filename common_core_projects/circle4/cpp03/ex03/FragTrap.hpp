#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:

	public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &copy);
	~FragTrap();
	void	highFiveGuys(void);
	static const int	hitpoints = 100;
	static const int	energy = 100;
	static const int	attackdmg = 30;
};
