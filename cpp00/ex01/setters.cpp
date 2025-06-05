/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:10:23 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/02 20:59:00 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

void	Contact::setFirstName(std::string name) {
	firstName = name;
}

void	Contact::setLastName(std::string name) {
	lastName = name;
}

void	Contact::setNickName(std::string name) {
	nickName = name;
}

void	Contact::setPhoneNumber(std::string number) {
	phoneNumber = number;
}

void	Contact::setDarkestSecret(std::string secret) {
	darkestSecret = secret;
}

void	Contact::setIndex(int currentIndex) {
	index = currentIndex;
}
