/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:58:24 by damachad          #+#    #+#             */
/*   Updated: 2024/03/18 15:55:00 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

std::string	Contact::get_first_name(void)
{
	return (_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (_last_name);
}

std::string	Contact::get_nickname(void)
{
	return (_nickname);
}

std::string Contact::get_phone_number(void)
{
	return (_phone_number);
}

std::string Contact::get_darkest_secret(void)
{
	return (_darkest_secret);
}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
