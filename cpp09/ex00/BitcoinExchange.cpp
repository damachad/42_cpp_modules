/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:49:56 by damachad          #+#    #+#             */
/*   Updated: 2024/06/13 13:42:50 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

BitcoinExchange::BitcoinExchange(void): dataMap()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & src)
{
	if (this != &src)
	{
		dataMap = src.dataMap;
	}
	return (*this);
}

void	BitcoinExchange::loadData(std::string filename)
{
	std::string 	line;
	std::ifstream 	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("could not open data.csv file.");

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("invalid fields in data.csv file.");
	while (std::getline(file, line))
	{
		std::string date;
		std::string price;
		std::stringstream strStream(line);

		std::getline(strStream, date, ',');
		strStream >> price;
		this->dataMap.insert(std::pair<std::string, float>(date, std::atof(price.c_str())));
	}
	file.close();
}

void	BitcoinExchange::printData(void) const
{
	std::map<std::string, float>::const_iterator it;
	for (it = this->dataMap.begin(); it != this->dataMap.end(); it++)
		std::cout << it->first << "  " << it->second << '\n';
}

size_t	BitcoinExchange::getMapSize(void) const
{
	return (this->dataMap.size());
}

bool	BitcoinExchange::isValidInput(std::string line)
{
	this->removeSpaces(line);
	if (line.empty() || line.find_first_of('|') == std::string::npos ||
	line.find_first_of('|') != line.find_last_of('|') ||
	line.find_first_of('|') == 0 || line.find_first_of('|') == line.length() - 1)
		return (false);
	return (true);
}

long	BitcoinExchange::toLongDate(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '-')
		{
			s.erase(s.begin() + i);
			i--;
		}
	}
	long dateLong = std::atol(s.c_str());
	return (dateLong);
}

float BitcoinExchange::getClosestDateValue(std::string date)
{
	long longDate = toLongDate(date);
	std::map<std::string, float>::const_iterator it;
	std::map<std::string, float>::const_iterator tmp = this->dataMap.end();
	int	dateMinInterval = INT_MAX;
	long dateDiff;
	for (it = this->dataMap.begin(); it != this->dataMap.end(); it++)
	{
		dateDiff = longDate - toLongDate(it->first);
		if (dateDiff > 0 && dateDiff < dateMinInterval)
		{
			dateMinInterval = dateDiff;
			tmp = it;
		}
	}
	if (tmp == this->dataMap.end())
		return (0);
	return (tmp->second);
}

std::tm * BitcoinExchange::parseDateTime(const char* datetimeString, const char* format)
{
	std::tm * tmStruct = new tm;
	std::memset(tmStruct, 0, sizeof(std::tm));
	if(!strptime(datetimeString, format, tmStruct)) // populates tm struct according to date str and format
	{
		delete tmStruct;
		return (NULL);
	}
	struct std::tm tmp = *tmStruct;
	mktime(tmStruct); // normalizes date (if 01/32 -> 02/01)
	if(!sameDates(&tmp, tmStruct))
	{
		delete tmStruct;
		return (NULL);
	}
	return (tmStruct);
}

bool	BitcoinExchange::sameDates(std::tm * d1, std::tm * d2)
{
	if (d1->tm_year != d2->tm_year || d1->tm_mon != d2->tm_mon \
	|| d1->tm_mday != d2->tm_mday)
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidDate(std::string date)
{
	if (date.length() != 10 || std::count(date.begin(), date.end(), '-') != 2)
		return (false);
	for (size_t i = 0; i < date.length(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
			return (false);
	}
	std::tm * parsedDate = this->parseDateTime(date.c_str(), "%Y-%m-%d");
	if (!parsedDate)
		return (false);	
	delete parsedDate;
	return (true);
}

bool	BitcoinExchange::isValidValue(std::string value) const
{
	bool sign = value[0] == '+' || value[0] == '-';

	for (size_t i = sign; i < value.length(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.')
			return (false);
	}
	if (value.find_first_of('.') != value.find_last_of('.') || \
	*(value.end() - 1) == '.')
		return (false);
	return (true);
}

bool	BitcoinExchange::isPositiveNumber(std::string value) const
{
	float number = std::atof(value.c_str());
	return (number >= 0);
}

bool	BitcoinExchange::isInLimit(std::string value) const
{
	long	number = std::atol(value.c_str());
	return (number	<= 1000);
}

void	BitcoinExchange::printValues(std::string date, std::string value)
{
	std::map<std::string, float>::const_iterator pos = this->dataMap.find(date);
	std::cout << date << " => " << value << " = ";
	if (pos != this->dataMap.end())
		std::cout << std::atof(value.c_str()) * pos->second << '\n';
	else
		std::cout << std::atof(value.c_str()) * getClosestDateValue(date) << '\n';
}

void	BitcoinExchange::removeSpaces(std::string & s)
{
	if (s.empty())
		return ;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (std::isspace(s[i]))
		{
			s.erase(s.begin() + i);
			i--;
		}
	}
}

void	BitcoinExchange::trimOuterSpaces(std::string & s)
{
	if (s.empty())
		return ;
	while (std::isspace(s[0]))
		s.erase(s.begin());
	while (std::isspace(s[s.length() - 1]))
		s.erase(s.end() - 1);
}

void	BitcoinExchange::processInput(std::string filename)
{
	std::string 	line;
	std::ifstream 	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("could not open file.");

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("invalid headers in input file.");
	while (std::getline(file, line))
	{
		std::string date;
		std::string price;
		std::string remainder;
		std::stringstream strStream(line);

		if (!this->isValidInput(line))
		{
			std::cerr << "Error: bad input => " << line << '\n';
			continue ;
		}
		std::getline(strStream, date, '|');
		strStream >> price;
		strStream >> remainder;
		removeSpaces(remainder);
		if (!remainder.empty())
		{
			std::cerr << "Error: bad input => " << line  << '\n';
			continue ;
		}
		this->trimOuterSpaces(date);
		this->trimOuterSpaces(price);
		if (!this->isValidDate(date))
			std::cerr << "Error: not a valid date => " << date << '\n';
		else if (!this->isValidValue(price))
			std::cerr << "Error: bad input => " << line << '\n';
		else if (!this->isPositiveNumber(price))
			std::cerr << "Error: not a positive number.\n";
		else if (!this->isInLimit(price))
			std::cerr << "Error: too large a number.\n";
		else
			this->printValues(date, price);
	}
	file.close();
}
