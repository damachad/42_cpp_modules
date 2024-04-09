/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:54:58 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 17:23:50 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("default"), _inventory(), _floor(), _floorCount(0)
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(Character const & src) : _name(src._name), _inventory(), _floor(), _floorCount(0)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}

Character::Character(std::string const & name) : _name(name), _inventory(), _floor(), _floorCount(0)
{
	std::cout << "Character name constructor called" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	if (_floor)
	{
		for (int i = 0; i < _floorCount; i++)
		{
			if (_floor[i])
				delete _floor[i];
		}
		delete[] _floor;
	}
	std::cout << "Character destructor called" << std::endl;
}

Character &	Character::operator=(Character const & src)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &src)
	{
		if (this->_name != src._name)
			this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &	Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{	
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Equiping " << m->getType() << std::endl;
			m = NULL;
			break;
		}
	}
	if (m)
		this->_floorPush(m);
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
	{
		this->_floorPush(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx] != NULL)
	{
		std::cout << "Using " << _inventory[idx]->getType();
		std::cout << " on " << target.getName() << std::endl;
		_inventory[idx]->use(target);
	}
}

void Character::_floorPush(AMateria* m)
{
	std::cout << "Dropping " << m->getType() << std::endl;
	if (!_floor)
	{
		_floor = new AMateria*[1];
		_floor[0] = m;
	}
	else
	{
		AMateria** tmp = new AMateria*[_floorCount + 1];
		for (int i = 0; i < _floorCount; i++)
			tmp[i] = _floor[i];
		tmp[_floorCount] = m;
		delete[] _floor;
		_floor = tmp;
	}
	_floorCount++;
}
