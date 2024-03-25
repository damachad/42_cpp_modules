/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:35 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 12:00:00 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z_ptr;
	z_ptr = newZombie("Zad");
	z_ptr->announce();
	randomChump("Zed");
	delete z_ptr;
	return (0);
}
