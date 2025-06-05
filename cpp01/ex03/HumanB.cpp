# include "HumanB.hpp"

//El constructor humanB no se inicializa con una arma, hay que setearla luego, por eso el atributo weapon
// debe ser un puntero, para inicializarlo como nul

HumanB::HumanB(std::string n) : name(n), weapon(NULL) {}

void	HumanB::attack() {
	if (weapon)
		std::cout	<< name << " attacks with their "
					<< weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon " << std::endl;
}

void	HumanB::setWeapon(Weapon& Weapon) {
	weapon = &Weapon;
}
