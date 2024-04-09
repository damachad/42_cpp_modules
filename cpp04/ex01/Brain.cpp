/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:30:54 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:41:02 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "I have no idea";
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &	Brain::operator=(Brain const & src)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

void	Brain::printIdeas(void)
{
	for (int i = 0; i < 100; i++)
		std::cout << this->_ideas[i] << std::endl;
}

void	Brain::printIdeaIndex(int i)
{
	std::cout << this->_ideas[i] << std::endl;
}

void	Brain::setIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}

void	Brain::cloneIdeas(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}
