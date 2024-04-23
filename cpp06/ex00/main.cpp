/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:42:12 by damachad          #+#    #+#             */
/*   Updated: 2024/04/17 20:28:48 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <input_to_convert>" << std::endl;
		return (1);
	}
	ScalarConverter::converter(argv[1]);
	return (0);
}
