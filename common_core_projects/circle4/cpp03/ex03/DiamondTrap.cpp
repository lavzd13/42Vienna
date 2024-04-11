#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap constructor called. Created object " YELLOW + name  + RESET << std::endl;
	this->_name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy = ScavTrap::energy;
	this->_attackdmg = FragTrap::_attackdmg;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap deconstructor called. Deleting object " YELLOW + this->_name + RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy._name + "_clap_name"), ScavTrap(copy._name), FragTrap(copy._name) {
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = copy;
}

DiamondTrap&	DiamondTrap::operator= (const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy operator called" << std::endl;
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energy = copy._energy;
	this->_attackdmg = copy._attackdmg;
	return *this;
}

void	DiamondTrap::whoAmI(void) const {
	std::cout << PEACH "DiamondTrap name: " + this->_name + RESET << std::endl;
	std::cout << PEACH "ClapTrap name: " + ClapTrap::_name + RESET << std::endl;
}
