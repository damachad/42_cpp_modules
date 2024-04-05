/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:42 by damachad          #+#    #+#             */
/*   Updated: 2024/04/05 11:11:12 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap bot("Bot");
	DiamondTrap bip("Bip");

	std::cout << std::endl;
	bot.getHp();
	bot.getEp();
	std::cout << std::endl;
	bip.getHp();
	bip.getEp();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		bot.attack(bip.getName());
		bot.getEp();
		bip.takeDamage(bot.getAttackD());
		bip.getHp();
	}
	std::cout << std::endl;
	bot.getEp();
	bip.getHp();
	bip.beRepaired(10);
	bip.attack(bot.getName());
	bip.getHp();
	bip.getEp();
	bip.whoAmI();
	bip.guardGate();
	bip.highFivesGuys();
	std::cout << std::endl;
	
	return (0);
}
