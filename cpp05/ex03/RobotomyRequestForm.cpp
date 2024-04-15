/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:54:25 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 10:52:46 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
	std::cout << "RobotomyRequestForm name constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	RobotomyRequestForm::executeOn(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "*Driling noises*\n";
	srand(time(0));
	if ((rand() % 20) >= 10)
		std::cout << this->getName() << " has been robotomized successfully.\n";
	else
		std::cout << "The robotomy has failed.\n";
}
