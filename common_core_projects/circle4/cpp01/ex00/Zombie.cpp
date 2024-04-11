#include "Zombie.hpp"

Zombie::Zombie() {
	this->name = "Why didn't you give me a name?";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "Zombie " + this->name << " is getting deleted." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name + ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) {
	return (this->name);
}

void	Zombie::setName(std::string str) {
	this->name = str;
}