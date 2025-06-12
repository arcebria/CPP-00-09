/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:44:02 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 21:15:49 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
			: ClapTrap(name) {
				hitPoints = 100;
				energyPoints = 100;
				attackDamage = 30;
				std::cout << "FragTrap created" << std::endl;
			}

FragTrap::~FragTrap(void) {
	std::cout	<< "FragTrap destroyed" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << name << " says: Do you want to high-fives bud?" << std::endl;
}

//--------------------------------------------------------------------------------------

void	FragTrap::attack(const std::string& target) {
	if (hitPoints == 0) {
		std::cout	<< "No hit points remains" << std::endl;
		return ;
	}
	else if (energyPoints == 0) {
		std::cout	<< "No energy points remains" << std::endl;
		return ;
	}
	std::cout	<< "FragTrap " << name << " attacks " << target
				<< ", causing " << attackDamage
				<< " points of damage!" << std::endl;
	energyPoints--;
}

void	FragTrap::beRepaired(unsigned int amount) {
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
