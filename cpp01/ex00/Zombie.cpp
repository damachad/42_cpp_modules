/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:37 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 11:54:09 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Creating a Zombie" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Creating a Zombie named " << name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroying " << _name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
