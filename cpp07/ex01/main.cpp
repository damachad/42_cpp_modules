/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:22:47 by damachad          #+#    #+#             */
/*   Updated: 2024/04/24 12:29:55 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	char	charArray[5] = {'a', 'b', 'c', 'd', 'e'};
	int		intArray[5] = {1, 2, 3, 4, 5};
	float	floatArray[5] = {1.4f, 3.5f, 4.7f, 6.5f, 8.6f};
	double	doubleArray[5] = {1.2, 3.2, 3.4, 4.5, 5.6};

	std::cout << "Char array elements: ";
	iter<char, void(*)(const char &)>(charArray, sizeof(charArray) / sizeof(char), printElement<char>);
	std::cout << std::endl;

	std::cout << "Int array elements: ";
	iter<int, void(*)(const int &)>(intArray, sizeof(intArray) / sizeof(int), printElement<int>);
	std::cout << std::endl;

	std::cout << "Float array elements: ";
	iter<float, void(*)(const float &)>(floatArray, sizeof(floatArray) / sizeof(float), printElement<float>);
	std::cout << std::endl;

	std::cout << "Double array elements: ";
	iter<double, void(*)(const double &)>(doubleArray, sizeof(doubleArray) / sizeof(double), printElement<double>);
	std::cout << std::endl;
	
	return (0);
}
