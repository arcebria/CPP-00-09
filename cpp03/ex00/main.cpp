#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	Arnau("Arnau");

	Arnau.attack("Comunista");
	Arnau.takeDamage(8);
	Arnau.beRepaired(8);
	// std::cout	<< "HitPoints: " << Arnau.getHitPoints() << std::endl
	// 			<< "EnergyPoints: " << Arnau.getEnergyPoints() << std::endl;
	return 0;
}
