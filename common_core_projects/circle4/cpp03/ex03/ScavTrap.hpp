#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	private:

	public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &copy);
	~ScavTrap();
	void	attack(std::string target);
	void	guardGate();
	static const int	hitpoints = 100;
	static const int	energy = 50;
	static const int	attackdmg = 20;
};
