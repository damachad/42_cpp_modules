/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:00:56 by damachad          #+#    #+#             */
/*   Updated: 2024/06/07 11:41:59 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe <positive integer sequence>\n";
		return (1);
	}
	PmergeMe sorter;
	if(!sorter.parseInput(argv))
	{
		std::cout << "Error: invalid input.\n";
		return (2);
	}
	std::cout << "Before: ";
	sorter.printVector();
	// sorter.printList();
	sorter.sortSequence();
	return (0);
}
