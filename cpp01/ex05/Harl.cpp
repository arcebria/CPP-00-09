/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:58:01 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/05 15:24:47 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

void	Harl::debug(void) {
	std::cout	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
				<< std::endl;
}

void	Harl::info(void) {
	std::cout	<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
				<< std::endl;
}
void	Harl::warning(void) {
	std::cout	<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
				<< std::endl;
}

void	Harl::error(void) {
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void	Harl::complain(std::string level) {

	void	(Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	int i = -1;
	while (++i < 4) {
		if (levels[i] == level)
			break;
	}

	if (i < 4)
		(this->*functions[i])();
}
