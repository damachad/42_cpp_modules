/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:45 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 11:57:55 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a new Zombie (stack) and announces it
void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}
