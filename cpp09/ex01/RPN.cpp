/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:07:20 by damachad          #+#    #+#             */
/*   Updated: 2024/05/22 11:49:56 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : stack()
{}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN::~RPN(void)
{}

RPN &	RPN::operator=(RPN const & src)
{
	if (this != &src)
	{
		stack = src.stack;
	}
	return (*this);
}

void	RPN::trimOuterSpaces(std::string & s)
{
	if (s.empty())
		return ;
	while (std::isspace(s[0]))
		s.erase(s.begin());
	while (std::isspace(s[s.length() - 1]))
		s.erase(s.end() - 1);
}

bool	RPN::isValidChars(std::string expression) const
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		if (strchr("+-*/", c) == NULL && !isdigit(c) && !isspace(c))
			return (false);
	}
	return (true);
}

bool	RPN::doOperation(char op)
{
	if (stack.size() < 2)
	{
		std::cerr << "Error: not enough numbers to do operation.\n";
		return (false);
	}
	int n1 = stack.top();
	stack.pop();
	int n2 = stack.top();
	stack.pop();
	int result = 0;
	if (op == '/' && n1 == 0)
	{
		std::cout << "Undefined\n";
		return (false);
	}
	switch (op)
	{
		case '+':
		{
			result = n2 + n1;
			break;
		}
		case '-':
		{
			result = n2 - n1;
			break;
		}
		case '*':
		{
			result = n2 * n1;
			break;
		}
		case '/':
		{
			result = n2 / n1;
			break;
		}
	}
	stack.push(result);
	return (true);
}

bool	RPN::calculate(std::string expression)
{
	size_t l = expression.length();
	size_t i = 0;
	while (i < l)
	{
		char currC = expression[i];
		char nextC = expression[i + 1];
		bool isSignNumber = strchr("+-", currC) && nextC && isdigit(nextC);
		if (isdigit(currC) || isSignNumber)
		{
			int number = std::atoi(expression.substr(i, l - i).c_str());
			stack.push(number);
		}
		else if ((strchr("+-*/", currC) && nextC && isspace(nextC)) || \
		(strchr("+-*/", currC) && !nextC))
		{
			if (!doOperation(currC))
				return (false);
		}
		if (isSignNumber)
			i++;
		while (isdigit(expression[i]))
			i++;
		while (isspace(expression[i]))
			i++;
		if ((strchr("+-*/", currC) && nextC && !isspace(nextC)) && !isSignNumber)
		{
			std::cerr << "Error: invalid input.\n";
			return (false);
		}
		else if (strchr("+-*/", currC) && !isSignNumber)
			i++;
	}
	return (true);
}

void	RPN::parseInput(std::string expression)
{
	trimOuterSpaces(expression);
	if (expression.empty())
	{
		std::cerr << "Error: empty input.\n";
		return;
	}
	if (!isValidChars(expression))
	{
		std::cerr << "Error: invalid input.\n";
		return;
	}
	if (!calculate(expression))
		return ;
	if (stack.size() != 1)
	{
		std::cerr << "Error: unbalanced number of numbers and operators.\n";
		return;
	}
	std::cout << stack.top() << std::endl;
}
