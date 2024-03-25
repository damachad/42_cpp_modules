/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:12:43 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 12:19:08 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	filter(int	i)
{
	Harl	harl;

	switch (i)
	{
		case 0:
			harl.complain("DEBUG");
			//fallthrough
		case 1:
			harl.complain("INFO");
			//fallthrough
		case 2:
			harl.complain("WARNING");
			//fallthrough
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "Not a valid level." << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		bool default_msg = true;
		std::string level = argv[1];
		std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (int i = 0; i < 4; i++)
		{
			if (level == levels[i])
			{
				default_msg = false;
				filter(i);
			}
		}
		if (default_msg)
		{
			std::cout << "[ Probably complaining about insignificant problems ]";
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "Please insert a level: ./harlFilter <level>";
		std::cout << std::endl;
	}
	return (0);
}
