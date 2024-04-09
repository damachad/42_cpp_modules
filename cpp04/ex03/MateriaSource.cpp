/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:55:21 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 17:26:10 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _slots()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._slots[i])
			this->_slots[i] = src._slots[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i])
			delete this->_slots[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & src)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_slots[i])
				delete this->_slots[i];
			if (src._slots[i])
				this->_slots[i] = src._slots[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{	
		if (_slots[i] == NULL)
		{
			_slots[i] = m;
			std::cout << "Learning " << m->getType() << std::endl;
			m = NULL;
			break;
		}
	}
	if (m)
		delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice" || type == "cure")
	{
		for (int i = 0; i < 4; i++)
		{
			if (_slots[i] && _slots[i]->getType() == type)
			{
				std::cout << "Creating " << _slots[i]->getType() << std::endl;
				return (_slots[i]->clone());
			}
		}
	}
	return (0);
}
