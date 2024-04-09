/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:55:09 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 17:24:42 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria::AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria::AMateria(src.type)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice &	Ice::operator=(Ice const & src)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

Ice*	Ice::clone(void) const
{
	return (new Ice(*this));
}
