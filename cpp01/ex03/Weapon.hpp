/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:23:02 by damachad          #+#    #+#             */
/*   Updated: 2024/03/19 16:28:09 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
	public:
		const std::string	&getType();
		void				setType(std::string new_type);
		
		Weapon(std::string type);
		Weapon(void);
		~Weapon(void);
		
	private:
		std::string	_type;
};

#endif