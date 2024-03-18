/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:45:56 by damachad          #+#    #+#             */
/*   Updated: 2024/02/19 11:34:07 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; j < (int)strlen(argv[i]); j++)
				std::cout << (char)toupper(argv[i][j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE NOISE *";
	std::cout << std::endl;
	return (0);
}
