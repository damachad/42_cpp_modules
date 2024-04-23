/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:10:56 by damachad          #+#    #+#             */
/*   Updated: 2024/04/19 14:19:59 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called." << std::endl;
}

Serializer::Serializer(Serializer const & src)
{
	std::cout << "Serializer copy constructor called." << std::endl;
	*this = src;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called." << std::endl;
}

Serializer &	Serializer::operator=(Serializer const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
