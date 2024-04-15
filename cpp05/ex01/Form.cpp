/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:54:01 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 11:04:25 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(0), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), \
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
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), \
_signed(0), _signGrade(signGrade), _executeGrade(execGrade)
{
	this->assessGrades(signGrade, execGrade);
	std::cout << "Form params constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form &	Form::operator=(Form const & src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

void	Form::assessGrades(int signGrade, int execGrade)
{
	try
	{
		if (signGrade < 1 || execGrade < 1)
			throw Form::GradeTooHighException();
		else if (signGrade > 150 || execGrade > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	Form::beSigned(Bureaucrat & user)
{
	if (user.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &	operator<<(std::ostream & o, Form const & src)
{
	o << src.getName() << ", form sign grade " << src.getSignGrade();
	o << ", execute grade " << src.getExecuteGrade() << ", ";
	if (src.getSigned())
		o << "signed.";
	else
		o << "not signed.";
	return (o);
}
