#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap (name, 100, 50, 20) {
	std::cout << "ScavTrap constructor with name called. Created object " << YELLOW << name << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap deconstructor called. Deleting object " << YELLOW << this->get_name() << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap("", 100, 50, 20) {
	std::cout << "Copy constructor called in the ScavTrap." << std::endl;
	*this = copy;
}

ScavTrap&	ScavTrap::operator= (const ScavTrap& copy) {
	(void)copy;
	std::cout << "Copy operator called in the ScavTrap." << std::endl;
	return *this;
}

void	ScavTrap::attack(std::string target) {
	if (this->_energy > 0 && this->_hitpoints > 0) {
		std::cout << MAGENTA "ScavTrap object " << this->_name + " attacks " + target;
		std::cout << ", causing " << this->_attackdmg << " points of damage!" << RESET << std::endl;
		this->_energy -= 1;
	}
	else if (this->_energy <= 0 && this->_hitpoints > 0)
		std::cout << RED << this->_name + " does not have enough energy for the attack!" << RESET << std::endl;
	else if (this->_hitpoints <= 0 && this->_energy > 0)
		std::cout << RED << this->_name + " is dead. Attack is not possible." << RESET << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << ORANGE << _name << " is now in the Gate keeper mode." << RESET << std::endl;
}
