/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:56:17 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:45:48 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal::Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src) : Animal::Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*(src._brain));
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &	Dog::operator=(Dog const & src)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src)
	{
		this->Animal::type = src.Animal::type;
		this->_brain->cloneIdeas(*(src._brain));
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}
