/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:53:34 by damachad          #+#    #+#             */
/*   Updated: 2024/03/18 14:09:00 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook		phonebook;
	std::string		choice;

	std::cout << "Welcome to PhoneBook.\n" << std::endl;
	while (1)
	{
		std::cout<< "Choose one of the following (in capital letters):\nADD for \
adding a new contact,\nSEARCH for displaying a specific contact,\nEXIT to exit \
the program:" << std::endl;
		std::cin >> choice;
		if (!std::cin)
		{
			if (std::cin.eof())
				return (0);
			std::cin.clear();
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (choice == "ADD")
			phonebook.add_contact();
		else if (choice == "SEARCH")
			phonebook.search_contacts();
		else if (choice == "EXIT")
		{
			std::cout << "\nExiting... Thank you for using PhoneBook." << std::endl;
			return (0);
		}
		else
			std::cout << "Please check if you are choosing a valid option." << std::endl;
		if (std::cin.eof())
			return (0);
	}
	return (0);
}
