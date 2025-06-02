/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:36:33 by arcebria          #+#    #+#             */
/*   Updated: 2025/05/30 19:37:20 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int	main(void) {
	PhoneBook phoneBook(0, 0);
	std::string input;
	while (1) {
		getline(std::cin, input);
		if (input == "ADD")
			phoneBook.addContact();
		if (input == "SEARCH")
			phoneBook.search();
		if (input == "EXIT")
			break;
	}
	return 0;
}
