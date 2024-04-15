/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:21 by damachad          #+#    #+#             */
/*   Updated: 2024/04/12 14:49:43 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << GREEN << "Constructors" << RESET << std::endl;
	Bureaucrat	sam("Sam", 20);

	std::cout << std::endl;
	std::cout << GREEN << "Bureaucrats" << RESET << std::endl;
	std::cout << sam << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Update Grade tests" << RESET << std::endl;
	std::cout << "Decrementing grade (higher value)" << std::endl;
	sam.decrementGrade();
	std::cout << sam << std::endl;
	std::cout << "Incrementing grade (lower value)" << std::endl;
	sam.incrementGrade();
	std::cout << sam << std::endl;
	std::cout << std::endl;

	std::cout << RED << "Invalid Grade tests" << RESET << std::endl;
	Bureaucrat	jack("Jack", 0);
	Bureaucrat	john("John", 151);
	Bureaucrat	zed("Zed", 150);
	std::cout << zed << std::endl;
	std::cout << "Decrementing grade (higher value)" << std::endl;
	zed.decrementGrade();
	std::cout << std::endl;
	std::cout << RED << "Destructors" << RESET << std::endl;
	
	return (0);
}
