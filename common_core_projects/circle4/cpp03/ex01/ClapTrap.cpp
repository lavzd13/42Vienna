#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Default constructor called. Creating object " << YELLOW << this->_name << RESET << std::endl;
	this->_hitpoints = 10;
	this->_energy = 10;
	this->_attackdmg = 0;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitpoint, unsigned int energy, unsigned int attackdmg) :
	_name(name) , _hitpoints(hitpoint) , _energy(energy), _attackdmg(attackdmg) {
		std::cout << "Constructor with all parameters called. Created object " << YELLOW << this->_name << RESET << std::endl;
	}
ClapTrap::~ClapTrap() {
	std::cout << "Deconstructor called. Object " << YELLOW << this->_name << RESET << " is delted." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energy = copy._energy;
	this->_attackdmg = copy._attackdmg;
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energy > 0 && this->_hitpoints > 0) {
		std::cout << CYAN << this->_name + " attacks " + target;
		std::cout << ", causing " << this->_attackdmg << " points of damage!" << RESET << std::endl;
		this->_energy -= 1;
	}
	else if (this->_energy <= 0 && this->_hitpoints > 0)
		std::cout << RED << this->_name + " does not have enough energy for the attack!" << RESET << std::endl;
	else if (this->_hitpoints <= 0 && this->_energy > 0)
		std::cout << RED << this->_name + " is dead. Attack is not possible." << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitpoints > 0) {
		std::cout << CYAN << this->_name + " took " << amount << " point of damage!" << RESET << std::endl;
		if (amount >= _hitpoints)
			this->_hitpoints = 0;
		else
			this->_hitpoints -= amount;
	}
	else
		std::cout << RED << this->_name + " is already dead. Hitpoints are " << this->_hitpoints << "." RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy > 0 && this->_hitpoints > 0) {
		if (amount == 1)
			std::cout << CYAN << this->_name + " repaired his hitpoints by " << amount << " point." << RESET << std::endl;
		else
			std::cout << CYAN << this->_name + " repaired his hitpoints by " << amount << " points." << RESET << std::endl;
		this->_energy -= 1;
		this->_hitpoints += amount;
	}
	else if (this->_energy <= 0 && this->_hitpoints > 0)
		std::cout << RED << this->_name + " does not have enough energy for the repair!" << RESET << std::endl;
	else if (this->_hitpoints <= 0 && this->_energy > 0)
		std::cout << RED << this->_name + " is dead. Repair is not possible." << RESET << std::endl;
}

void	ClapTrap::displayHitpoints(void) const {
	if (this->_hitpoints == 1)
		std::cout << CYAN << this->_name + " have " << this->_hitpoints << " hitpoint." << RESET << std::endl;
	else if (this->_hitpoints > 0)
		std::cout << CYAN << this->_name + " have " << this->_hitpoints << " hitpoints." << RESET << std::endl;
	else
		std::cout << RED << this->_name + " is dead. No hitpoints left." << RESET << std::endl;
}

const std::string&	ClapTrap::get_name(void) const {
	return this->_name;
}
