/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:18 by damachad          #+#    #+#             */
/*   Updated: 2024/03/19 16:13:09 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 3;
	Zombie	*zombies = zombieHorde(N, "Zack");;
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);	
}
