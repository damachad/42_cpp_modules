/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:54:04 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 15:44:23 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm(void);
		AForm(AForm const & src);
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm(void);

		AForm &  operator=(AForm const & src);

		std::string const	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				beSigned(Bureaucrat & user);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	
	protected:
	
		virtual void	assessGrades(int signGrade, int execGrade);
		
	private:

		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_executeGrade;


};

std::ostream &	operator<<(std::ostream & o, AForm & src);

#endif // FORM_HPP
