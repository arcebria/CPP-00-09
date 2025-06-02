/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:42:23 by arcebria          #+#    #+#             */
/*   Updated: 2025/05/30 18:58:53 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>


class	Contact {
	private:

	public:
	int	index;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

class	PhoneBook {
	private:
	Contact contactArray[8];
	int	contactCount;
	int	currentIndex;

	public:
	PhoneBook(int cc, int ci);
	void addContact();
	void search();
};

	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();

#endif
