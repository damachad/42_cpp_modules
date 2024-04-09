/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:56:12 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:59:46 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal::AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const & src) : AAnimal::AAnimal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*(src._brain));
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &	Cat::operator=(Cat const & src)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src)
	{
		this->AAnimal::type = src.AAnimal::type;
		this->_brain->cloneIdeas(*(src._brain));
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}
