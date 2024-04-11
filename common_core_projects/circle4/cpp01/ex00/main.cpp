#include "Zombie.hpp"

int	main(void) {
	Zombie	z("Milorad");
	Zombie	a;
	a.setName("Nis");
	a.announce();
	Zombie*	test = newZombie("Boban");
	test->announce();
	z.announce();
	randomChump("RandomChump");
	std::string str = "";
	while (std::getline(std::cin, str) && str == "")
		if (str != "")
			break;
	delete test;
}