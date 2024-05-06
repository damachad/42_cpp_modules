/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:21:42 by damachad          #+#    #+#             */
/*   Updated: 2024/05/06 16:18:48 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << "Testing small Span\n";
	Span smallSpan(5);
	
	std::cout << "Adding { -3, 1, 2 }.\n";
	smallSpan.addNumber(-3);
	smallSpan.addNumber(1);
	smallSpan.addNumber(2);
	try
	{
		std::cout << RED << "Try adding numbers out of bounds, range(4, 7):\n" << RESET;
		smallSpan.addRange(4, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Array size: " << smallSpan.getSize() << std::endl;
	std::cout << "Array: ";
	smallSpan.printArray();
	std::cout << std::endl;
	try
	{
		std::cout << "Longest span: " << smallSpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Shortest span: " << smallSpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nTesting big Span\n";
	Span span(20000);
	try
	{
		std::cout << "Adding range of numbers (1, 20000).\n";
		span.addRange(1, 20000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << RED << "Try adding number when array is full { -3 }:\n" << RESET;
		span.addNumber(-3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Array size: " << span.getSize() << std::endl;
	// std::cout << "Array: ";
	// span.printArray();
	// std::cout << std::endl;
	try
	{
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
