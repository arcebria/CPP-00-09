#include "Weapon.hpp"

Weapon::Weapon(std::string t) : type(t) {}
// Weapon::~Weapon() {
// 	std::cout << "Weapon destroyed" << std::endl;
// }

std::string const& Weapon::getType(void) {
	return type;
}

void	Weapon::setType(std::string weaponType) {
	type = weaponType;
}

