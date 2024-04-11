#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _w(NULL) {
	this->_name = name;
}

HumanB::~HumanB() {

}

void	HumanB::setWeapon(Weapon &w) {
	this->_w = &w;
}

void	HumanB::attack() {
	if (this->_w == NULL)
		std::cout << this->_name << " attacks without weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their weapon " << this->_w->getType() << std::endl;
}