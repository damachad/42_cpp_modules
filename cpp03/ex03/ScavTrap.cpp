/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:46:52 by damachad          #+#    #+#             */
/*   Updated: 2024/04/04 16:35:04 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap::ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int attack) : ClapTrap::ClapTrap(name, hp, ep, attack)
{
	std::cout << "ScavTrap params constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

void	ScavTrap::attack(const std::string &name)
{
	if (this->_energy_points> 0 && this->_hit_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << name;
		std::cout << ", causing " << this->_attack_damage << " points of damage!";
		std::cout << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}
