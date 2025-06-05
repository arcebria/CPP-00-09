/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:42:23 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/03 21:02:31 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include "Contact.hpp"

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

#endif
