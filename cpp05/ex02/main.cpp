/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:21 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 15:46:52 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << GREEN << "Constructors" << RESET << std::endl;
	Bureaucrat	sam("Sam", 5);
	Bureaucrat	john("John", 45);
	Bureaucrat	karen("Karen", 130);

	AForm		*shrub = new ShrubberyCreationForm("home");
	AForm		*robot = new RobotomyRequestForm("bender");
	AForm		*president = new PresidentialPardonForm("Jack");
	
	std::cout << std::endl;
	std::cout << GREEN << "Bureaucrats" << RESET << std::endl;
	std::cout << sam << std::endl;
	std::cout << john << std::endl;
	std::cout << karen << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Forms" << RESET << std::endl;
	std::cout << *shrub << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *president << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "OK sign tests" << RESET << std::endl;
	sam.signForm(*shrub);
	std::cout << *shrub << std::endl;
	john.signForm(*robot);
	std::cout << *robot << std::endl;
	std::cout << std::endl;
	std::cout << RED << "Low grade sign tests" << RESET << std::endl;
	karen.signForm(*president);
	std::cout << std::endl;
	std::cout << RED << "No signed, execute test" << RESET << std::endl;
	sam.executeForm(*president);
	std::cout << std::endl;
	sam.signForm(*president);
	std::cout << std::endl;
	std::cout << GREEN << "OK execute test" << RESET << std::endl;
	sam.executeForm(*shrub);
	john.executeForm(*robot);
	sam.executeForm(*president);
	std::cout << std::endl;
	std::cout << RED << "Low grade execute test" << RESET << std::endl;
	john.executeForm(*president);
	std::cout << std::endl;
	std::cout << RED << "Destructors called" << RESET << std::endl;
	delete shrub;
	delete robot;
	delete president;
	std::cout << std::endl;

	return (0);
}
