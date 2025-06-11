/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:30:12 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 20:10:03 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
			: ClapTrap(name) {
				hitPoints = 100;
				energyPoints = 50;
				attackDamage = 20;
				std::cout << "ScavTrap created" << std::endl;
			}
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destroyed" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (hitPoints == 0) {
		std::cout	<< "No hit points remains" << std::endl;
		return ;
	}
	else if (energyPoints == 0) {
		std::cout	<< "No energy points remains" << std::endl;
		return ;
	}
	std::cout	<< "ScavTrap " << name << " attacks " << target
				<< ", causing " << attackDamage
				<< " points of damage!" << std::endl;
	energyPoints--;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout	<< "No hit points remains" << std::endl;
		return ;
	}
	else if (energyPoints == 0) {
		std::cout	<< "No energy points remains" << std::endl;
		return ;
	}
	std::cout	<< name << " gains " << amount << " of hit points" << std::endl;
	hitPoints += amount;
	if (hitPoints > 100)
		hitPoints = 100;
	energyPoints--;
}

