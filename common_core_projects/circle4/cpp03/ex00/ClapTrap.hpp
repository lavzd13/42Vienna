#pragma once

#include <iostream>

#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define GRAY		"\033[1m\033[90m"
#define RED			"\033[1m\033[31m"
#define GREEN		"\033[1m\033[32m"
#define YELLOW		"\033[1m\033[33m"
#define BLUE		"\033[1m\033[34m"
#define MAGENTA		"\033[1m\033[35m"
#define CYAN		"\033[1m\033[36m"
#define WHITE		"\033[1m\033[37m"
#define DARK_GREEN	"\033[1m\033[38;5;22m"
#define PEACH		"\033[1m\033[38;5;216m"
#define ORANGE		"\033[1m\033[38;5;208m"

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy;
		unsigned int	_attackdmg;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap &copy);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	displayHitpoints(void) const;
};
