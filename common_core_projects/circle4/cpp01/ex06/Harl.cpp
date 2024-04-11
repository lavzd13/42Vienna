#include "Harl.hpp"
#include <string>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::print(std::string level) {
	std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*Ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	if (level == str[0] || level == str[1] || level == str[2] || level == str[3]) {
		switch (level[0]) {
			case 'D':
				((this->*Ptr[0])());
			case 'I':
				((this->*Ptr[1])());
			case 'W':
				((this->*Ptr[2])());
			case 'E':
				((this->*Ptr[3])());
				break ;
		}
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}