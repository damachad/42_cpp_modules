/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:42 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 10:29:11 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	const WrongAnimal* k = new WrongCat();
	const WrongCat* m = new WrongCat();

	std::cout << std::endl;
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	
	std::cout << k->getType() << ": ";
	k->makeSound();
	std::cout << m->getType() << " as WrongCat: ";
	m->makeSound();
	std::cout << std::endl;
	
	delete meta;
	delete j;
	delete i;
	delete k;
	delete m;
	
	return (0);
}
