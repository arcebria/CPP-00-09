#include "HumanA.hpp"
#include "HumanB.hpp"

int	main() {
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);

	bob.attack(); // Bob attacks with their crude spiked club
	club.setType("some other type of club");
	bob.attack(); // Bob attacks with their some other type of club

	// Weapon club = Weapon("crude spiked club");
	// HumanB jim("Jim");

	// jim.attack(); // Jim has no weapon
	// jim.setWeapon(club);
	// jim.attack(); // Jim attacks with their crude spiked club
	// club.setType("some other type of club");
	// jim.attack(); // Jim attacks with their some other type of club
}
