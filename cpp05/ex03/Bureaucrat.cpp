/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:01:17 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 10:39:41 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->setGrade(src._grade);
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrat parameters constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void	Bureaucrat::incrementGrade(void)
{
		this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
		this->setGrade(this->_grade + 1);
}

void	Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << ".\n";
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << ".\n";
	}
	
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.executeOn(*this);
		std::cout << this->getName() << " executed " << form.getName() << ".\n";
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName();
		std::cout << " because " << e.what() << ".\n";
	}
	
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (o);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
