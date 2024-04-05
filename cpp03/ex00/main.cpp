/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:42 by damachad          #+#    #+#             */
/*   Updated: 2024/04/03 16:26:23 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap bot("Bot");
	ClapTrap bip("Bip");

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Bip HP: " << bip.getHp() << std::endl;
		std::cout << "Bip EP: " << bip.getEp() << std::endl;
		std::cout << "Bot EP: " << bot.getEp() << std::endl;
		bot.attack(bip.getName());
		bip.takeDamage(bot.getAttackD());
		bip.beRepaired(2);
	}
	std::cout << "Bip HP: " << bip.getHp() << std::endl;
	std::cout << "Bip EP: " << bip.getEp() << std::endl;
	std::cout << "Bot EP: " << bot.getEp() << std::endl;
	bot.attack(bip.getName());
	bip.beRepaired(2);
	std::cout << std::endl;
	
	return (0);
}
