#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : _weapon(w) {
	this->_name = name;
}

HumanA::~HumanA() {

}

void	HumanA::attack() {
	std::cout << this->_name << " attacks with their weapon " << this->_weapon.getType();
	std::cout << std::endl;
}
