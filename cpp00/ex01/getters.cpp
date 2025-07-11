/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:10:23 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/02 20:52:40 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

std::string Contact::getFirstName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickName() {
	return nickName;
}

std::string	Contact::getPhoneNumber() {
	return phoneNumber;
}

std::string	Contact::getDarkestSecret() {
	return darkestSecret;
}

int	Contact::getIndex() {
	return index;
}
