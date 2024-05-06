/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:36:34 by damachad          #+#    #+#             */
/*   Updated: 2024/05/06 16:05:35 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

int main()
{
	std::cout << YELLOW << "Testing MutantStack" << RESET << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "MutantStack top: ";
	std::cout << mstack.top() << std::endl;
	std::cout << std::endl;
	
	mstack.pop();
	
	std::cout << "MutantStack size: ";
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(-3);
	mstack.push(70);
	mstack.push(999);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	std::cout << "MutantStack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::cout << "MutantStack size: ";
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;
	std::stack<int> s(mstack);
	
	MutantStack<int>::iterator itEnd = mstack.end();
	while (!mstack.empty())
	{
		--itEnd;
		std::cout << "Deleting " << *itEnd << " from MutantStack" << std::endl;
		mstack.pop();			
	}

	std::cout << std::endl;
	std::cout << YELLOW << "List Output" << RESET << std::endl;
	{
		std::list<int> mstack;
	
		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << "List back: ";
		std::cout << mstack.back() << std::endl;
		std::cout << std::endl;
		mstack.pop_back();
		
		std::cout << "List size: ";
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(-3);
		mstack.push_back(70);
		mstack.push_back(999);

		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		std::cout << "List: " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		std::cout << "List size: ";
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;
		std::list<int> s(mstack);

		std::list<int>::iterator itEnd;
		while (!mstack.empty())
		{
			itEnd = mstack.end();
			--itEnd;
			std::cout << "Deleting " << *itEnd << " from list" << std::endl;
			mstack.pop_back();			
		}

	}
	return 0;
}
