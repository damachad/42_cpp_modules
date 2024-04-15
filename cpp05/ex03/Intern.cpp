/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:11:19 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 15:25:56 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
}

Intern &	Intern::operator=(Intern const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

AForm *	Intern::cloneShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *	Intern::cloneRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *	Intern::clonePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*f[3])(std::string) = {&Intern::cloneShrubbery, \
	&Intern::cloneRobotomy, &Intern::clonePresidential};
	int	found = 0;
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
			found = i;
	}
	if (found == 0)
	{
		std::cout << "No form with that name exists." << std::endl;
		return (0);
	}
	std::cout << "Intern creates " << form << std::endl;
	
	return ((this->*f[found])(target));
}
