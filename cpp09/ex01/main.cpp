/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:03:57 by damachad          #+#    #+#             */
/*   Updated: 2024/05/21 17:03:50 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN <Reverse Polish Notation expression>.\n";
		std::cout << "Example: '3 4 +'\n";
		return (1);
	}
	RPN	calculator;
	calculator.parseInput(argv[1]);
	return (0);
}
