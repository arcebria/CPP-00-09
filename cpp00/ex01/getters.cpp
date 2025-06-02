/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:10:23 by arcebria          #+#    #+#             */
/*   Updated: 2025/05/30 14:20:58 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

std::string getFirstName() {
	std::string firstName;
	std::cout << "Ingrese nombre: ";
	std::cin >> firstName;
	return firstName;
}

std::string getLastName() {
	std::string lastName;
	std::cout << "Ingrese apellido: ";
	std::cin >> lastName;
	return lastName;
}

std::string getNickName() {
	std::string	nickName;
	std::cout << "Ingrese apodo: ";
	std::cin >> nickName;
	return nickName;
}

std::string	getPhoneNumber() {
	std::string	phoneNumber;
	std::cout << "Ingrese numero telefono: ";
	std::cin >> phoneNumber;
	return phoneNumber;
}

std::string	getDarkestSecret() {
	std::string	darkestSecret;
	std::cout << "Ingrese secreto mas oscuro: ";
	std::cin >> darkestSecret;
	return darkestSecret;
}
