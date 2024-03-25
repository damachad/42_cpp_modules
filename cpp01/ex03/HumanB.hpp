/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:22:11 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 12:25:46 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB{
	public:
		void	attack();
		void	setWeapon(Weapon &weapon);
		
		HumanB(std::string name);
		~HumanB(void);
		
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif