#include <cstdlib> 
#include "Array.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#define MAX_VAL 10

int main(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "Constructors" << RESET << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		std::cout << GREEN << "Deep copy test" << RESET << std::endl;
		std::cout << GREEN << "Print original array: " << RESET << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << numbers[i] << ' ';
		}
		std::cout << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << GREEN << "Changing copy array to 5" << RESET << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			test[i] = 5;
		}
		std::cout << GREEN << "Print copy array: " << RESET << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << test[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << GREEN << "Print original array: " << RESET << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << tmp[i] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << GREEN << "Comparison against array of int: " << RESET;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
			return 1;
		}
	}
	std::cout << GREEN << "OK" << RESET << std::endl;
	try
	{
		std::cout << RED << "Try to access index -2" << RESET << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		std::cout << RED << "Try to access MAX index" << RESET << std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << GREEN << "Print refilled array: " << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << RED << "Calling destructors" << RESET << '\n';
	delete [] mirror;

	return 0;
}
