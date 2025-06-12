#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :
        ClapTrap(name + "_clap_name"),
        ScavTrap(name + "_scav_name"),
        FragTrap(name + "_frag_name"),
        name(name) {
            hitPoints = 100;
            energyPoints = 50;
            attackDamage = 30;
            std::cout << "DiamondTrap created" << std::endl;
        }

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destroyed" << std::endl;
}

void    DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) {
    std::cout   << "DiamondTrap name: " << name << std::endl
                << "ClapTrap name: " << ClapTrap::name << std::endl;
}