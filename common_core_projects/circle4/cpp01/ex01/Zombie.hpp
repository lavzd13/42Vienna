#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
	std::string name;

	public:
	Zombie();
	~Zombie();
	void	announce(void);
	void		setName(std::string str);
	std::string	getName(void);
};

Zombie* zombieHorde(int N, std::string name);
void	deleteHorde(Zombie* horde);

#endif