/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:52:02 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 18:52:03 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
