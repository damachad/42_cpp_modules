/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:54:04 by damachad          #+#    #+#             */
/*   Updated: 2024/04/10 19:45:07 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form(void);
		Form(Form const & src);
		Form(std::string name, int signGrade, int execGrade);
		~Form(void);

		Form &  operator=(Form const & src);

		std::string const	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				beSigned(Bureaucrat & user);

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

	private:

		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_executeGrade;

		void	assessGrades(int signGrade, int execGrade);

};

std::ostream &	operator<<(std::ostream & o, Form const & src);

#endif // FORM_HPP
