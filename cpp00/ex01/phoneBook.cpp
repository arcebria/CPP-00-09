/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:41:40 by arcebria          #+#    #+#             */
/*   Updated: 2025/05/30 21:17:32 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook(int cc, int ci) : contactCount(cc), currentIndex(ci) {}

std::string	truncateString(std::string string) {
	if (string.length() > 10)
		string = string.substr(0, 9) + ".";
	return string;
}

void	PhoneBook::addContact() {
	std::string	firstName = truncateString(getFirstName());
	std::string	lastName = truncateString(getLastName());
	std::string	nickName = truncateString(getNickName());
	std::string	phoneNumber = truncateString(getPhoneNumber());
	std::string	darkestSecret = truncateString(getDarkestSecret());

	Contact contact;
	contact.firstName = firstName;
	contact.lastName = lastName;
	contact.nickName = nickName;
	contact.phoneNumber = phoneNumber;
	contact.darkestSecret = darkestSecret;
	if (contactCount < 8) {
		contact.index = currentIndex;
		contactArray[currentIndex] = contact;
		contactCount++;
		currentIndex++;
	}
	else if (contactCount == 8) {
		currentIndex = currentIndex % 8;
		contact.index = currentIndex;
		contactArray[currentIndex] = contact;
		currentIndex++;
	}
}

void	PhoneBook::search() {
	std::cout	<< std::setw(10) << "INDEX" << " | "
				<< std::setw(10) << "FIRST NAME" << " | "
				<< std::setw(10) << "LAST NAME" << " | "
				<< std::setw(10) << "NICK NAME" << " | " << std::endl;
	for (int i= 0; i < contactCount; i++)
		std::cout	<< std::setw(10) << contactArray[i].index << " | "
					<< std::setw(10) << contactArray[i].firstName << " | "
					<< std::setw(10) << contactArray[i].lastName << " | "
					<< std::setw(10) << contactArray[i].nickName << " | " << std::endl;
	int	index;
	while (1) {
		if (currentIndex == 0) {
			std::cout << "No hay ningun contacto que buscar." << std::endl;
			return;
		}
		std::cout << "Ingrese Index: ";
		std::cin >> index;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Entrada invalida, ingrese de nuevo el INDEX." << std::endl;
		}
		else if (index < 0 || index > currentIndex - 1)
			std::cout << "Index fuera de rango, ingrese de nuevo el INDEX." << std::endl;
		else
			break ;
	}
	std::cout	<< "FIRST NAME: " << contactArray[index].firstName << "\n"
				<< "LAST NAME: " << contactArray[index].lastName << "\n"
				<< "NICK NAME: " << contactArray[index].nickName << "\n"
				<< "PHONE NUMBER: " << contactArray[index].phoneNumber << "\n"
				<< "DARKEST SECRET: " << contactArray[index].darkestSecret << std::endl;
}
