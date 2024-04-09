/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:56:24 by damachad          #+#    #+#             */
/*   Updated: 2024/04/09 12:02:04 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << GREEN << "Subject Test" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	std::cout << GREEN << "Extra Tests" << RESET << std::endl;
	std::cout << "Using unexisting Materia" << std::endl;
	me->use(2, *bob);
	std::cout << std::endl;
	std::cout << "Unequip" << std::endl;
	me->unequip(0);
	std::cout << "Using unequiped Materia" << std::endl;
	me->use(0, *bob);
	std::cout << std::endl;
	std::cout << "Unequiping unexisting Materia" << std::endl;
	me->unequip(3);
	std::cout << std::endl;
	std::cout << GREEN << "Learn extra Materia Test" << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;
	std::cout << GREEN << "Materia Type Test" << RESET << std::endl;
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	*ice = *cure;
	std::cout << ice->getType() << std::endl;
	std::cout << std::endl;
	std::cout << GREEN <<"Deep Copy Test" << RESET << std::endl;
	Character basic("john");
	{
		Character person = basic;
		person.equip(src->createMateria("ice"));
		basic.equip(src->createMateria("cure"));
		std::cout << "Person" << std::endl;
		person.use(0, *bob);
		std::cout << "Basic" << std::endl;
		basic.use(0, *bob);
	}
	std::cout << std::endl;
	std::cout << GREEN <<"Multiple Equip Test" << RESET << std::endl;
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));
	std::cout << std::endl;
	std::cout << GREEN <<"Check Equip Position Test" << RESET << std::endl;
	me->use(0, *bob);
	std::cout << std::endl;

	std::cout << RED <<"Calling Destructors" << RESET << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	std::cout << std::endl;
	delete ice;
	delete cure;
	std::cout << std::endl;

	return (0);
}
