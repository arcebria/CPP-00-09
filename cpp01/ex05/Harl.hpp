/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:58:03 by arcebria          #+#    #+#             */
/*   Updated: 2025/06/05 14:17:23 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class	Harl {
	private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public:
	Harl(void);
	void	complain(std::string level);
};

#endif
