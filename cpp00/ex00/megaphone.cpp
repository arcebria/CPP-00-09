/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:00:00 by arcebria          #+#    #+#             */
/*   Updated: 2025/05/29 14:26:36 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

int	main(int ac, char **av){
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string input;
	for (int i = 1; i < ac; i++) {
		input = av[i];
		for (int j = 0; j < (int)input.length(); j++)
			input[j] = std::toupper(input[j]);
		std::cout << input;
	}
	std::cout << "\n";
	return 0;
}
