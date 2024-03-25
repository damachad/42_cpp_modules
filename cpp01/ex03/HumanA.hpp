/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:22:47 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 12:25:15 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA{
	public:
		void	attack();
		
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		
	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif