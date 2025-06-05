/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adders.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:10:23 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/03 21:12:44 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

std::string Contact::addFirstName() {
	std::string firstName;
	while (1) {
		std::cout << "Ingrese nombre: ";
		if (!std::getline(std::cin, firstName)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detectado. Saliendo." << std::endl;
				std::exit(0);
			}
			std::cin.clear();
			firstName.clear();
		}
		if (firstName.empty())
			continue;
		else
			break;
	}
	return firstName;
}

std::string Contact::addLastName() {
	std::string lastName;
	while (1) {
		std::cout << "Ingrese apellido: ";
		if (!std::getline(std::cin, lastName)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detectado. Saliendo." << std::endl;
				std::exit(0);
			}
			std::cin.clear();
			lastName.clear();
		}
		if (lastName.empty())
			continue;
		else
			break;
	}
	return lastName;
}

std::string Contact::addNickName() {
	std::string	nickName;
	while (1) {
		std::cout << "Ingrese mote: ";
		if (!std::getline(std::cin, nickName)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detectado. Saliendo." << std::endl;
				std::exit(0);
			}
			std::cin.clear();
			nickName.clear();
		}
		if (nickName.empty())
			continue;
		else
			break;
	}
	return nickName;
}

std::string	Contact::addPhoneNumber() {
	std::string	phoneNumber;
	while (1) {
		std::cout << "Ingrese numero de telefono: ";
		if (!std::getline(std::cin, phoneNumber)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detectado. Saliendo." << std::endl;
				std::exit(0);
			}
			std::cin.clear();
			phoneNumber.clear();
		}
		if (phoneNumber.empty())
			continue;
		else
			break;
	}
	return phoneNumber;
}

std::string	Contact::addDarkestSecret() {
	std::string	darkestSecret;
	while (1) {
		std::cout << "Ingrese secreto: ";
		if (!std::getline(std::cin, darkestSecret)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detectado. Saliendo." << std::endl;
				std::exit(0);
			}
			std::cin.clear();
			darkestSecret.clear();
		}
		if (darkestSecret.empty())
			continue;
		else
			break;
	}
	return darkestSecret;
}
