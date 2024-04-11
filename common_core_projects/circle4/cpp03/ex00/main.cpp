#include "ClapTrap.hpp"

int	main(void) {
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
