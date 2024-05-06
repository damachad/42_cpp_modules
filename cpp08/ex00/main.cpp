/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:29:05 by damachad          #+#    #+#             */
/*   Updated: 2024/05/06 17:14:49 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>
# include <list>

int	main(void)
{
	std::vector<int> v;
	std::list<int> l;
	int	toFind = 4;
	int	toNotFind = 12;
	
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		l.push_back(i);
	}	
	std::cout << "Vector: ";
	std::vector<int>::const_iterator iter;
	for (iter = v.begin(); iter != v.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	std::cout << "List: ";
	std::list<int>::const_iterator iterList;
	for (iterList = l.begin(); iterList != l.end(); ++iterList) {
		std::cout << *iterList << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Vector find: " << std::endl;
	try
	{
		std::cout << "Looking for: " << toFind << std::endl;
		int found = easyfind<std::vector<int> >(v, toFind);
		std::cout << "Found: " << found << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Looking for: " << toNotFind << std::endl;
		int found = easyfind<std::vector<int> >(v, toNotFind);
		std::cout << "Found: " << found << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "List find: " << std::endl;
	try
	{
		std::cout << "Looking for: " << toFind << std::endl;
		int found = easyfind<std::list<int> >(l, toFind);
		std::cout << "Found: " << found << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Looking for: " << toNotFind << std::endl;
		int found = easyfind<std::list<int> >(l, toNotFind);
		std::cout << "Found: " << found << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
