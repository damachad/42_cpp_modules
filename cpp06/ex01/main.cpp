/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:09:51 by damachad          #+#    #+#             */
/*   Updated: 2024/04/23 09:20:13 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void	printData(Data *data)
{
	std::cout << "data.i: " << data->i << std::endl;
	std::cout << "data.c: " << data->c << std::endl;
}

int	main(void)
{
	Data test = {2, 'r'};
	Data *dataPtr;
	uintptr_t ptr;
	
	std::cout << "Data Before Serializer" << std::endl;
	printData(&test);
	std::cout << "ptr address: " << &test << std::endl;
	ptr = Serializer::serialize(&test);
	dataPtr = Serializer::deserialize(ptr);
	std::cout << "uintptr: " << ptr << std::endl;
	std::cout << "ptr address: " << dataPtr << std::endl;
	std::cout << "Data After Serializer" << std::endl;
	printData(&test);
	std::cout << "Data Ptr After Serializer" << std::endl;
	printData(dataPtr);
	test.i = 20;
	test.c = 'a';
	std::cout << "Data After Change" << std::endl;
	printData(&test);
	std::cout << "Data Ptr After Change" << std::endl;
	printData(dataPtr);
	dataPtr->i = 367;
	dataPtr->c = 'c';
	std::cout << "Data After Change through Ptr" << std::endl;
	printData(&test);
	std::cout << "Data Ptr After Change through Ptr" << std::endl;
	printData(dataPtr);
	
	return (0);
}
