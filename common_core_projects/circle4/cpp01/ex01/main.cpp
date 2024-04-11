#include "Zombie.hpp"

int	main(void) {
	Zombie *horda = zombieHorde(5, "Horde");
	for (int i = 0; i < 5; i++)
		horda[i].announce();
	std::string str = "";
	while (std::getline(std::cin, str) && str == "")
		if (str != "")
			break;
	deleteHorde(horda);
}