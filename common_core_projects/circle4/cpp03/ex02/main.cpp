#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	std::cout << std::endl << BOLD "#-------------------------------CLAPTRAP--------------------------------#" RESET << std::endl;
	{
	ClapTrap	clap("ClapTrap");
	clap.attack("Gospodina");
	clap.displayHitpoints();
	clap.takeDamage(5);
	clap.displayHitpoints();
	clap.beRepaired(5);
	clap.displayHitpoints();
	clap.takeDamage(11);
	clap.displayHitpoints();
	clap.attack("Gospodina");
	clap.beRepaired(11);
	}
	std::cout << std::endl << BOLD "#----------------------------END OF CLAPTRAP----------------------------#" RESET << std::endl;
	std::cout << std::endl << BOLD "#-------------------------------SCAVTRAP--------------------------------#" RESET << std::endl;
	{
	ScavTrap	scav("ScavTrap");
	scav.attack("Gospodina");
	scav.displayHitpoints();
	scav.takeDamage(50);
	scav.displayHitpoints();
	scav.beRepaired(20);
	scav.displayHitpoints();
	scav.takeDamage(101);
	scav.displayHitpoints();
	scav.beRepaired(100);
	scav.attack("Gospodina");
	scav.guardGate();
	}
	std::cout << std::endl << BOLD "#----------------------------END OF SCAVTRAP----------------------------#" RESET << std::endl;
	std::cout << std::endl << BOLD "#-------------------------------FRAGTRAP--------------------------------#" RESET << std::endl;
	{
	FragTrap	frag("FragTrap");
	frag.attack("Gospodina");
	frag.displayHitpoints();
	frag.takeDamage(50);
	frag.displayHitpoints();
	frag.beRepaired(25);
	frag.displayHitpoints();
	frag.takeDamage(101);
	frag.displayHitpoints();
	frag.beRepaired(100);
	frag.attack("Gospodina");
	frag.highFiveGuys();
	}
	std::cout << std::endl << BOLD "#----------------------------END OF FRAGTRAP----------------------------#" RESET << std::endl;
}
