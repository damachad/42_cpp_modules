/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:23:25 by damachad          #+#    #+#             */
/*   Updated: 2024/03/19 16:28:31 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("nothing"){}

Weapon::~Weapon(void){}

Weapon::Weapon(std::string type) : _type(type){}

const std::string	&Weapon::getType()
{
	std::string &typeREF = _type;
	return (typeREF);
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}
