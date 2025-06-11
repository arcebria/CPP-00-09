/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:42:45 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/11 21:15:08 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap {
	public:
	FragTrap(std::string name);
	~FragTrap(void);
	void	highFivesGuys(void);
	void	beRepaired(unsigned int amount);
	void	attack(const std::string& target);
};

#endif
