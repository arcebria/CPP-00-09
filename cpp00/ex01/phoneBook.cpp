/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:41:40 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/03 21:10:49 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook(int cc, int ci) : contactCount(cc), currentIndex(ci) {}

Contact::Contact(void) {}

std::string	truncateString(std::string string) {
	if (string.length() > 10)
		string = string.substr(0, 9) + ".";
	return string;
}

//hacer funciones addFirstName... con el cin
//y hacer los getters bien, como el index

void	PhoneBook::addContact() {
	Contact contact;
	std::string	firstName = contact.addFirstName();
	std::string	lastName = contact.addLastName();
	std::string	nickName = contact.addNickName();
	std::string	phoneNumber = contact.addPhoneNumber();
	std::string	darkestSecret = contact.addDarkestSecret();

	contact.setFirstName(firstName);
	contact.setLastName(lastName);
	contact.setNickName(nickName);
	contact.setPhoneNumber(phoneNumber);
	contact.setDarkestSecret(darkestSecret);
	if (contactCount < 8) {
		contact.setIndex(currentIndex);
		contactArray[currentIndex] = contact;
		contactCount++;
		currentIndex++;
	}
	else if (contactCount == 8) {
		currentIndex = currentIndex % 8;
		contact.setIndex(currentIndex);
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
		std::cout	<< std::setw(10) << contactArray[i].getIndex() << " | "
					<< std::setw(10) << truncateString(contactArray[i].getFirstName()) << " | "
					<< std::setw(10) << truncateString(contactArray[i].getLastName()) << " | "
					<< std::setw(10) << truncateString(contactArray[i].getNickName()) << " | " << std::endl;
	int	index;
	while (1) {
		if (currentIndex == 0) {
			std::cout << "No hay ningun contacto que buscar." << std::endl;
			return;
		}
		std::cout << "Ingrese Index: ";
		std::cin >> index;
		if (std::cin.eof()) {
			std::cout << "\nEOF detectado. Saliendo" << std::endl;
			std::exit(0);
		}
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
	std::cout	<< "FIRST NAME: " << contactArray[index].getFirstName() << "\n"
				<< "LAST NAME: " << contactArray[index].getLastName() << "\n"
				<< "NICK NAME: " << contactArray[index].getNickName() << "\n"
				<< "PHONE NUMBER: " << contactArray[index].getPhoneNumber() << "\n"
				<< "DARKEST SECRET: " << contactArray[index].getDarkestSecret() << std::endl;
}
