/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:42 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 11:57:03 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a new Zombie (heap) and returns a pointer to it
Zombie*	newZombie(std::string name)
{
	Zombie	*zombie1 = new Zombie(name);
	if (!zombie1)
		std::cout << "Memory allocation failed." << std::endl;
	return (zombie1);
}
