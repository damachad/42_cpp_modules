/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:39:55 by damachad          #+#    #+#             */
/*   Updated: 2024/04/23 09:25:21 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	std::cout << "ScalarConverter copy constructor called." << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}


static bool	isInvalidFloat(std::string const & in)
{
	bool wrongAfterDot = in.find_first_of('.') != std::string::npos && \
	in.find_first_of('.') + 1 <= in.length() - 1 && !isdigit(in[in.find_first_of('.') + 1]);
	bool signWrongPlace = in.find_first_of("+-") != std::string::npos && \
	in.find_first_of("+-") > 0;
	
	if (in.find_first_of("+-") != in.find_last_of("+-") || \
	in.find_first_of('f') != in.find_last_of('f') || \
	in.find_first_of('.') != in.find_last_of('.') || \
	wrongAfterDot || signWrongPlace || (in.find_first_of('f') != std::string::npos \
	&& in.find_first_of('f') != in.length() - 1) || \
	(in.find_first_of("+-") == 0 && in.find_first_of('f') == 1))
		return (true);
	else
		return (false);
}


static bool	isFloatChar(char c)
{
	char chars[4] = {'+', '-', '.', 'f'};

	for (int i = 0; i < 4; i++)
	{
		if (c == chars[i])
			return (true);
	}
	return (false);
}

static bool	isNumber(std::string const & input)
{
	if (isInvalidFloat(input))
		return (false);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && !isFloatChar(input[i]))
			return (false);
	}
	return (true);
}

static bool	isChar(std::string const & input)
{
	return (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]));
}

static int	NanInfType(std::string const & input)
{
	std::string lit_f[4] = {"nanf", "inff", "-inff", "+inff"};
	std::string lit_d[4] = {"nan", "inf", "-inf", "+inf"};

	for (int i = 0; i < 4; i++)
	{
		if (input == lit_d[i])
			return (DOUBLE);
	}
	for (int i = 0; i < 4; i++)
	{
		if (input == lit_f[i])
			return (FLOAT);
	}
	return (0);
}

static bool	isInt(std::string const & input)
{
	bool sign = input[0] == '+' || input[0] == '-';
	
	for (size_t i = sign; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	if (input.length() > 11)
		return (false);
	else if (std::strtol(input.c_str(), 0, 10) > INT_MAX || \
	std::strtol(input.c_str(), 0, 10) < INT_MIN)
		return (false);
	return (true);
}

static bool	isFloat(std::string const & input)
{
	if (input.length() > 1 && *(input.end() - 1) == 'f')
		return (true);
	return (false);
}

static bool	isDouble(std::string const & input)
{
	if (input.length() > 1 && input.find_first_of('.') != std::string::npos && \
	*(input.end() - 1) != '.')
		return (true);
	return (false);
}

static int	getNumberType(std::string const & input)
{
	if (isInt(input))
		return (INT);
	else if (isFloat(input))
		return (FLOAT);
	else if (isDouble(input))
		return (DOUBLE);
	else
		return (ERROR);
}

static int	getType(std::string const & input)
{
	if (NanInfType(input))
		return (NanInfType(input));
	else if (isChar(input))
		return (CHAR);
	else if (isNumber(input))
		return (getNumberType(input));
	else
		return (ERROR);
}

static void	printTypesError(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	printTypesChar(std::string const & input)
{
	std::cout << "char: '" << static_cast<char>(input[0]) << '\'' << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

static void	printTypesInt(std::string const & in)
{
	int i = std::atoi(in.c_str());
	char c = static_cast<char>(i);
	
	if (std::isprint(c) && i < 255 && i > 0)
		std::cout << "char: '" << c << '\'' << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i);
	if (std::atof(in.c_str()) == std::atoi(in.c_str()))
		std::cout << ".0";
	std::cout << "f\ndouble: " << static_cast<double>(i);
	if (std::atof(in.c_str()) == std::atoi(in.c_str()))
		std::cout << ".0";
	std::cout << std::endl;
}

static void	printTypesFloat(std::string const & in)
{
	std::string lit_f[4] = {"nanf", "inff", "-inff", "+inff"};
	float f = static_cast<float>(std::atof(in.c_str()));
	char c = static_cast<char>(f);
	bool impossible = false;
	
	for (int i = 0; i < 4; i++)
	{
		if (in == lit_f[i])
		{
			std::cout << "char: impossible" << c << std::endl;
			std::cout << "int: impossible" << c << std::endl;
			impossible = true;
		}
	}
	if (std::isprint(c) && !impossible && f < 255 && f > 0)
		std::cout << "char: '" << c << '\'' << std::endl;
	else if (!impossible)
		std::cout << "char: Non displayable" << std::endl;
	if (!impossible)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f;
	if (std::atof(in.c_str()) == std::atoi(in.c_str()))
		std::cout << ".0";
	std::cout << "f\ndouble: "  << static_cast<double>(f);
	if (std::atof(in.c_str()) == std::atoi(in.c_str()))
		std::cout << ".0";
	std::cout << std::endl;
}

static void	printTypesDouble(std::string const & in)
{
	std::string lit_d[4] = {"nan", "inf", "-inf", "+inf"};
	double d = std::atof(in.c_str());
	char c = static_cast<char>(d);
	bool impossible = false;
	
	for (int i = 0; i < 4; i++)
	{
		if (in == lit_d[i])
		{
			std::cout << "char: impossible" << c << std::endl;
			std::cout << "int: impossible" << c << std::endl;
			impossible = true;
		}
	}
	if (std::isprint(c) && !impossible && d < 255 && d > 0)
		std::cout << "char: '" << c << '\'' << std::endl;
	else if (!impossible)
		std::cout << "char: Non displayable" << std::endl;
	if (!impossible)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: "  << static_cast<float>(d);
	if (std::atof(in.c_str()) == std::atoi(in.c_str()))
		std::cout << ".0";
	std::cout << "f\ndouble: " << d;
	if (std::atof(in.c_str()) == std::atoi(in.c_str()))
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::converter(std::string const & input)
{
	if (input.empty())
	{
		std::cout << "Error: empty input\n";
		return ;
	}
	int	type = getType(input);
	
	switch (type)
	{
	case ERROR:
		printTypesError();
		break;
	case CHAR:
		printTypesChar(input);
		break;
	case INT:
		printTypesInt(input);
		break;
	case FLOAT:
		printTypesFloat(input);
		break;
	case DOUBLE:
		printTypesDouble(input);
		break;
	}
}
