/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:51:52 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 21:17:16 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ScavTrap	ScavTrap("ScavTrapito");
	FragTrap	FragTrap("FragTrapito");

	ScavTrap.attack("Humanito");
	ScavTrap.takeDamage(8);
	ScavTrap.beRepaired(10);
	ScavTrap.guardGate();
	std::cout	<< "HitPoints: " << ScavTrap.getHitPoints() << std::endl
				<< "EnergyPoints: " << ScavTrap.getEnergyPoints() << std::endl;


	FragTrap.attack("Other humanito");
	FragTrap.takeDamage(50);
	FragTrap.beRepaired(30);
	FragTrap.highFivesGuys();
	std::cout	<< "HitPoints: " << FragTrap.getHitPoints() << std::endl
				<< "EnergyPoints: " << FragTrap.getEnergyPoints() << std::endl;
	return 0;
}
