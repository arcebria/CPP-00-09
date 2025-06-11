/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:51:52 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 20:11:37 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	Robot("Robotito");

	Robot.attack("Humanito");
	Robot.takeDamage(8);
	Robot.beRepaired(10);
	Robot.guardGate();
	std::cout	<< "HitPoints: " << Robot.getHitPoints() << std::endl
				<< "EnergyPoints: " << Robot.getEnergyPoints() << std::endl;
	return 0;
}
