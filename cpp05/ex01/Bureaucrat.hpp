/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:01:08 by damachad          #+#    #+#             */
/*   Updated: 2024/04/10 19:39:49 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;
class Bureaucrat
{

	public:

		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const name, int grade);
		~Bureaucrat(void);

		Bureaucrat &  operator=(Bureaucrat const & src);

		std::string const	getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form & form);

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
		int					_grade;

		void				setGrade(int grade);

};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & src);

#endif // BUREAUCRAT_HPP
