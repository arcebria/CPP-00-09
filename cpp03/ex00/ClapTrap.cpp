/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:52:08 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 18:52:09 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap object created" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap object destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (hitPoints == 0) {
		std::cout	<< "No hit points remains" << std::endl;
		return ;
	}
	else if (energyPoints == 0) {
		std::cout	<< "No energy points remains" << std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << name << " attacks " << target
				<< ", causing " << attackDamage
				<< " points of damage!" << std::endl;
	energyPoints--;
}

void	ClapTrap::beRepaired(unsigned int amount) {
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
	if (hitPoints > 10)
		hitPoints = 10;
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << name << " is already dead" << std::endl;
	}
	std::cout	<< name << " takes " << amount << " points of damage" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
}

// int	ClapTrap::getEnergyPoints(void) {
// 	return	energyPoints;
// }

// int	ClapTrap::getHitPoints(void) {
// 	return	hitPoints;
// }
