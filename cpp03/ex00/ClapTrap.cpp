/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:47 by damachad          #+#    #+#             */
/*   Updated: 2024/04/04 16:35:04 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : _name(src._name), _hit_points(src._hit_points), _energy_points(src._energy_points), _attack_damage(src._attack_damage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hit_points = src._hit_points;
		this->_energy_points= src._energy_points;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &name)
{
	if (this->_energy_points> 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << name;
		std::cout << ", causing " << this->_attack_damage << " points of damage!";
		std::cout << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	else
	{
		if (this->_hit_points >= amount)
		{	
			this->_hit_points -= amount;
			std::cout << "ClapTrap " << this->_name << " is attacked";
			std::cout << ", receiving " << amount << " points of damage!";
			std::cout << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->_name << " is attacked";
			std::cout << ", receiving " << this->_hit_points << " points of damage!";
			std::cout << std::endl;
			this->_hit_points = 0;
		}
		if (this->_hit_points == 0)
			std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points> 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself";
		std::cout << ", replenishing " << amount << " points of damage!";
		std::cout << std::endl;
		this->_hit_points += amount;
		this->_energy_points--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is unable to repair itself." << std::endl;
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

unsigned int	ClapTrap::getHp(void)
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEp(void)
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::getAttackD(void)
{
	return (this->_attack_damage);
}
