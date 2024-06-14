/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:36:32 by damachad          #+#    #+#             */
/*   Updated: 2024/06/13 13:17:30 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		std::cout << "could not open file." << '\n';
		return (-1);
	}
	BitcoinExchange dataManager;
	try
	{
		dataManager.loadData("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what();
		std::cerr << " Check that 'data.csv' is present in the current directory.\n";
		return (-1);
	}
	try
	{
		dataManager.processInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}
