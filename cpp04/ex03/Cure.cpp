/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:55:03 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 17:24:52 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria::AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria::AMateria(src.type)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &	Cure::operator=(Cure const & src)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

Cure*	Cure::clone(void) const
{
	return (new Cure(*this));
}
