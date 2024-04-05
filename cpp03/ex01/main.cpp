/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:42 by damachad          #+#    #+#             */
/*   Updated: 2024/04/04 16:59:41 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap bot("Bot");
	ScavTrap bip("Bip");

	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		bip.getHp();
		bot.getEp();
		bot.attack(bip.getName());
		bip.takeDamage(bot.getAttackD());
	}
	bip.getHp();
	bot.getEp();
	bip.getEp();
	bip.beRepaired(10);
	bip.getHp();
	bip.getEp();
	bot.attack(bip.getName());
	bip.takeDamage(bot.getAttackD());
	bip.getHp();
	bot.getEp();
	bip.getEp();
	bot.attack(bip.getName());
	bip.takeDamage(bot.getAttackD());
	bip.getHp();
	bip.beRepaired(10);
	bip.attack(bot.getName());
	bot.getEp();
	bip.getEp();
	bip.guardGate();
	std::cout << std::endl;
	
	return (0);
}
