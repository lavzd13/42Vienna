#include "Zombie.hpp"

void	deleteHorde(Zombie* horde) {
	delete[] horde;
}

Zombie* zombieHorde(int N, std::string name) {
	int	i = 0;
	Zombie* horde = new Zombie[N];
	while (i < N) {
		horde[i].setName(name);
		i++;
	}
	return (&horde[0]);
}