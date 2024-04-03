/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:31:15 by damachad          #+#    #+#             */
/*   Updated: 2024/04/02 15:58:44 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iomanip>
#include <cstring>
# include <limits>

#define GREY "\033[90m"
#define YELLOW "\033[93m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

char	**createGrid(int height, int width)
{
	char** grid = new char*[height];
	
    for (int i = 0; i < height; i++)
	{
        grid[i] = new char[width];
	}
	return (grid);
}

void	deleteGrid(char** grid, int height)
{
	for (int i = 0; i < height; i++)
		delete[] grid[i];
	delete[] grid;
}

void drawTriangle(Point a, Point b, Point c, Point p)
{
	Point const	a2(1, 0);
	Point const	b2(10, 0);
	Point const	c2(0, 10);

	
	char	fill = '0';
	char	empty = '.';
    Fixed	minX = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX());
    Fixed	maxX = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX());
    Fixed	minY = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY());
    Fixed	maxY = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY());
    int		width = maxX.toInt() - minX.toInt() + 3;
    int		height = maxY.toInt() - minY.toInt() + 3;

	char	**grid = createGrid(height, width);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
		{
            if (bsp(a2, b2, c2, Point(x, y)))
                grid[y][x] = fill;
			else
				grid[y][x] = empty;
		}	
    }
    for (int y = height - 1; y >= 0; y--)
    {
        std::cout << GREY << std::setfill('0') << std::setw(2) << y << " " << RESET;
        for (int x = 0; x < width; x++)
        {
            if ((Fixed)x == p.getX() && (Fixed)y == p.getY() && bsp(a, b, c, p))
                std::cout << BOLD << GREEN << "Y  " << RESET;
            else if ((Fixed)x == p.getX() && (Fixed)y == p.getY() && !bsp(a, b, c, p))
                std::cout << BOLD << RED << "N  " << RESET;
            else if (grid[y][x] == fill)
                std::cout << YELLOW << grid[y][x] << "  " << RESET;
			else
				std::cout << GREY << grid[y][x] << "  " << RESET;
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int x = 0; x < width; x++)
        std::cout << GREY << std::setfill('0') << std::setw(2) << x << " " << RESET;
    std::cout << std::endl;
	deleteGrid(grid, height);
}

Point	point_coordinates(void)
{
	float	x, y;

	while (1)
	{
		std::cout << "Enter point coordinate x: ";
		std::cin >> x;
		if (!std::cin)
		{
			if (std::cin.eof())
				exit(0);
			std::cin.clear();
		}
		else if (x > -2147483648 && x < 2147483648.99609375)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (1)
	{
		std::cout << "Enter point coordinate y: ";
		std::cin >> y;
		if (!std::cin)
		{
			if (std::cin.eof())
				exit(0);
			std::cin.clear();
		}
		else if (y > -2147483648 && y < 2147483648.99609375)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	Point		p(x, y);
	return (p);
}

int	main(void)
{
	Point const	a(1, 1);
	Point const	b(8, 1);
	Point const	c(1, 8);

	drawTriangle(a, b, c, Point(-1, -1));
	std::cout << "A (" << a.getX() << ", " << a.getY() << ");" << std::endl;
	std::cout << "B (" << b.getX() << ", " << b.getY() << ");" << std::endl;
	std::cout << "C (" << c.getX() << ", " << c.getY() << ");" << std::endl;
	
	Point		p = point_coordinates();
	std::cout << "P (" << p.getX() << ", " << p.getY() << ");" << std::endl;
	
	drawTriangle(a, b, c, p);
	if (bsp(a, b, c, p))
		std::cout << GREEN << "Point is inside the triangle" << RESET << std::endl;
	else
		std::cout << RED << "Point is not inside the triangle" << RESET << std::endl;
	
	return (0);
}
