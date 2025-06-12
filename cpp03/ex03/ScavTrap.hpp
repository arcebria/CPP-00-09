/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:51:42 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 20:10:02 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
	ScavTrap(std::string name);
	~ScavTrap(void);
	void	guardGate(void);
	void	beRepaired(unsigned int amount);
	void	attack(const std::string& target);
};

#endif
