/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:21 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 11:05:37 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << GREEN << "Constructors" << RESET << std::endl;
	Bureaucrat	sam("Sam", 10);
	Bureaucrat	john("John", 30);
	Form		test("Test", 20, 10);

	std::cout << std::endl;
	std::cout << GREEN << "Bureaucrats" << RESET << std::endl;
	std::cout << sam << std::endl;
	std::cout << john << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Forms" << RESET << std::endl;
	std::cout << test << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "OK sign test" << RESET << std::endl;
	sam.signForm(test);
	std::cout << std::endl;
	std::cout << RED << "KO sign test" << RESET << std::endl;
	john.signForm(test);
	std::cout << std::endl;
	std::cout << RED << "Invalid grade test" << RESET << std::endl;
	Form		invalid("Test2", 0, 151);
	std::cout << std::endl;
	std::cout << RED << "Destructors called" << RESET << std::endl;

	return (0);
}
