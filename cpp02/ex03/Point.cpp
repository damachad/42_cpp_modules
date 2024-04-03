/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:05:07 by damachad          #+#    #+#             */
/*   Updated: 2024/03/01 15:59:33 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(float const x, float const y) : _x(x), _y(y)
{}	

Point::Point(Point const & src) : _x(src._x), _y(src._y)
{}

Point::~Point(void)
{}

Fixed	Point::getX(void) const
{
	return (Fixed(this->_x));
}

Fixed	Point::getY(void) const
{
	return (Fixed(this->_y));
}

Point & Point::operator=(Point const & src)
{
	if (this != &src)
	{
		Fixed(this->_x) = src.getX();
		Fixed(this->_y) = src.getY();
	}
	return (*this);
}

bool	Point::operator==(Point const & ref) const
{
	return (this->getX() == ref.getX() && this->getY() == ref.getY());
}
