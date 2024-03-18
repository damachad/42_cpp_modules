/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:36:19 by damachad          #+#    #+#             */
/*   Updated: 2024/03/18 15:58:01 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(-1), _display_all(false)
{}

PhoneBook::~PhoneBook(void)
{}

bool	PhoneBook::_check_number(std::string number)
{
	if (number.length() < 3 || number.length() > 14)
		return (false);
	if (number[0] == '+' || std::isdigit(number[0]))
	{
		for (size_t i = 1; i < number.length(); i++)
		{
			if (!std::isdigit(number[i]))
				return (false);
		}
		return (true);
	}
	return (false);
	
}

std::string	PhoneBook::_add_info(std::string msg)
{
	size_t	size;
	std::string	key;
	
	size = 0;
	while (size == 0)
	{
		std::cout << msg;
		getline(std::cin, key);
		if (std::cin.eof())
			exit(0);
		size = key.length();
		if (msg == "Phone Number: " && size > 0 && !_check_number(key))
		{
			std::cout << "Please insert a valid phone number." << std::endl;
			size = 0;
		}
	}
	return (key);
}

void	PhoneBook::add_contact(void)
{
	_index++;
	if (_index == 7)
		_display_all = true;
	else if (_index > 7)
	{
		std::cout << "\nMaximum contacts reached. Replacing oldest contact..." << std::endl;
		_index = 0;
	}
	std::cout << "\nPlease insert the following information \
(no empty fields are allowed):" << std::endl;
	_contacts[_index].set_first_name(_add_info("First Name: "));
	_contacts[_index].set_last_name(_add_info("Last Name: "));
	_contacts[_index].set_nickname(_add_info("Nickname: "));
	_contacts[_index].set_phone_number(_add_info("Phone Number: "));
	_contacts[_index].set_darkest_secret(_add_info("Darkest Secret: "));
	std::cout << "Contact added.\n" << std::endl;
	return;
}

std::string	truncate_data(std::string data)
{
	if (data.length() > 10)
	{
		data[9] = '.';
		return (data.substr(0, 10));
	}
	return (data);
}

void	PhoneBook::_get_contact_info(void)
{
	int	index;

	while (true)
	{
		std::cout << "\nPlease insert intended entry index (only one number): ";
		std::cin >> index;
		if (!std::cin)
		{
			if (std::cin.eof())
				return;
			std::cin.clear();
		}
		else if (index > 0 && index <= _index + 1)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "\nFirst Name: " << _contacts[index - 1].get_first_name() << std::endl;
	std::cout << "Last Name: " << _contacts[index - 1].get_last_name() << std::endl;
	std::cout << "Nickame: " << _contacts[index - 1].get_nickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index - 1].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index - 1].get_darkest_secret() << std::endl << std::endl;
}

void	PhoneBook::search_contacts(void)
{
	int	max;
	
	std::cout << std::endl << std::right << std::setw(10) << "Index" \
	<< '|' << std::right<< std::setw(10) << "First Name" << '|' \
	<< std::right << std::setw(10) << "Last Name" << '|' \
	<< std::right<< std::setw(10) << "Nickname" << '|' << std::endl;
	if (_index == -1)
	{
		std::cout << "\nNo contacts saved yet.\n" << std::endl;
		return;
	}
	if (_display_all)
		max = 7;
	else
		max = _index;
	for (int i = 0; i <= max; i++)
	{
		std::cout << std::right << std::setw(10) << i + 1 << '|' \
		<< std::right<< std::setw(10) << truncate_data(_contacts[i].get_first_name()) << '|' \
		<< std::right << std::setw(10) << truncate_data(_contacts[i].get_last_name()) << '|' \
		<< std::right<< std::setw(10) << truncate_data(_contacts[i].get_nickname()) << '|' \
		<< std::endl;
	}
	_get_contact_info();
	return;
}
