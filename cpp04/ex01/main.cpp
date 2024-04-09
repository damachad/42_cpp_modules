/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:42 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:49:51 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	const Animal* animals[4] = {};
	
	std::cout << std::endl;
	std::cout << GREEN << "Animal Array Test" << RESET << std::endl;
	for (int a = 0; a < 4; a++)
	{
		if (a < 4 / 2)
			animals[a] = new Dog();
		else
			animals[a] = new Cat();
		std::cout << animals[a]->getType() << ": ";
		animals[a]->makeSound();
	}
	std::cout << std::endl;
	std::cout << GREEN << "Deep Copy Test" << RESET << std::endl;
	Cat basic;
	{
		Cat tmp;
		tmp = basic;
		std::cout << "basics's ideas: ";
		basic.getBrain()->printIdeaIndex(1);
		std::cout << "tmp's ideas: ";
		tmp.getBrain()->printIdeaIndex(1);
		basic.getBrain()->setIdea("I'm a cat");
		std::cout << "tmp's ideas after changing basic's ideas: ";
		tmp.getBrain()->printIdeaIndex(1);
		std::cout << "basics's ideas after change: ";
		basic.getBrain()->printIdeaIndex(1);
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "Calling Destructors" << RESET << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;
	for (int a = 0; a < 4; a++)
		delete animals[a];
	std::cout << std::endl;

	return (0);
}
