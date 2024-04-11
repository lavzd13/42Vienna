#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	this->_hitpoints = 100;
	this->_energy = 100;
	this->_attackdmg = 30;
	std::cout << "FragTrap constructor called. Created object " << YELLOW << name << "." RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap deconstructor called. Deleting object " << YELLOW + this->_name + "." RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy._name, 100, 100, 30) {
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = copy;
}

FragTrap&	FragTrap::operator= (const FragTrap& copy) {
	std::cout << "FragTrap copy operator called" << std::endl;
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energy = copy._energy;
	this->_attackdmg = copy._attackdmg;
	return *this;
}

void	FragTrap::highFiveGuys(void) {
	std::cout << GREEN "FragTrap, displaying positive high five request." RESET << std::endl;
}
