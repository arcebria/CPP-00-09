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

#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	diamond("Diamante");

	diamond.attack("Protestante");
	diamond.whoAmI();
	std::cout	<< "HitPoints: " << diamond.getHitPoints() << std::endl
				<< "EnergyPoints: " << diamond.getEnergyPoints() << std::endl
				<< "AttackDamage: " << diamond.getAttackDamage()
				<< std::endl;
	return 0;
}
