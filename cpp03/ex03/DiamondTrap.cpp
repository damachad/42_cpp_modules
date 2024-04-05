/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:43:16 by damachad          #+#    #+#             */
/*   Updated: 2024/04/04 16:38:28 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap::ClapTrap(src), ScavTrap::ScavTrap(src), FragTrap::FragTrap(src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name + "_clap_name", 100, 50, 30), _name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & src)
{
	if (this != &src)
	{
		ScavTrap::operator=(src);
		this->_name = src._name;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My DiamondTrap name is: " << this->_name;
	std::cout << ", and my ClapTrap name is: " << ClapTrap::getName();
	std::cout << std::endl;
}
