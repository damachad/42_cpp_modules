/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:54:20 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 15:44:23 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
     std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	std::cout << "PresidentialPardonForm name constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
     std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw NotSigned();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
