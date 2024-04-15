/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:11:22 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 15:21:55 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern &  operator=(Intern const & src);

		AForm *makeForm(std::string form, std::string target);
		AForm *cloneShrubbery(std::string target);
		AForm *cloneRobotomy(std::string target);
		AForm *clonePresidential(std::string target);

};

#endif // INTERN_HPP
