/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:54:30 by damachad          #+#    #+#             */
/*   Updated: 2024/04/11 15:05:13 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
     std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
	std::cout << "ShrubberyCreationForm name constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
     std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	ShrubberyCreationForm::executeOn(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::ofstream shrubbery((std::string(this->getName()) + std::string("_shrubbery")).c_str());
	for (int i = 0; i < 5; i++)
	{
		shrubbery << "       ###            ### \n" \
					"      #o###          #o### \n" \
					"    #####o###      #####o### \n" \
					"   #o#\\#|#/###    #o#\\#|#/### \n" \
					"    ###\\|/#o#      ###\\|/#o# \n" \
					"     # }|{  #       # }|{  # \n" \
					"ejm97  }|{     ejm97  }|{ \n"\
					"\n";
	}
	shrubbery.close();
}
