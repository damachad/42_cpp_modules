/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:54:28 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 15:41:33 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &  operator=(RobotomyRequestForm const & src);

		virtual void		execute(Bureaucrat const & executor) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP
