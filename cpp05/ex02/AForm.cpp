/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:54:01 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 15:44:23 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(0), _signGrade(150), _executeGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), \
_signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	try
	{
		this->assessGrades(src._signGrade, src._executeGrade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), \
_signed(0), _signGrade(signGrade), _executeGrade(execGrade)
{
	this->assessGrades(signGrade, execGrade);
	std::cout << "AForm params constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &	AForm::operator=(AForm const & src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	AForm::beSigned(Bureaucrat & user)
{
	if (user.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char *AForm::NotSigned::what() const throw()
{
	return ("form is not signed");
}

std::ostream &	operator<<(std::ostream & o, AForm & src)
{
	o << src.getName() << ", AForm sign grade " << src.getSignGrade();
	o << ", execute grade " << src.getExecuteGrade() << ", ";
	if (src.getSigned())
		o << "signed.";
	else
		o << "not signed.";
	return (o);
}

void	AForm::assessGrades(int signGrade, int execGrade)
{
	try
	{
		if (signGrade < 1 || execGrade < 1)
			throw AForm::GradeTooHighException();
		else if (signGrade > 150 || execGrade > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
