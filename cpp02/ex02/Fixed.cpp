/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:31:09 by damachad          #+#    #+#             */
/*   Updated: 2024/04/02 15:12:51 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::Fixed(int const n)
{
	this->_n = n * (1 << this->_fbits);
}

Fixed::Fixed(float const n)
{
	this->_n = roundf(n * (1 << this->_fbits));
}

Fixed::~Fixed(void)
{}

int	Fixed::getRawBits(void)const
{
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_n / (1 << this->_fbits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_n / (float)(1 << this->_fbits));
}

Fixed &	Fixed::operator=(Fixed const & src)
{
	if (this != &src)
		this->_n = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->toFloat() > (float)rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toFloat() >= (float)rhs.toFloat());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->toFloat() < (float)rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->toFloat() <= (float)rhs.toFloat());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->toFloat() == (float)rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->toFloat() != (float)rhs.toFloat());
}

Fixed Fixed::operator++(void)
{
	++this->_n;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	*this = *this + 0.00390625f;
	return (tmp);
}

Fixed Fixed::operator--(void)
{
	--this->_n;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	*this = *this - 0.00390625f;
	return (tmp);
}

Fixed &	Fixed::min(Fixed & l, Fixed & r)
{
	if (l.toFloat() < r.toFloat())
		return (l);
	else
		return (r);
}

Fixed const &	Fixed::min(Fixed const & l, Fixed const & r)
{
	if (l.toFloat() < r.toFloat())
		return (l);
	else
		return (r);
}

Fixed &	Fixed::max(Fixed & l, Fixed & r)
{
	if (l.toFloat() > r.toFloat())
		return (l);
	else
		return (r);
}

Fixed const &	Fixed::max(Fixed const & l, Fixed const & r)
{
	if (l.toFloat() > r.toFloat())
		return (l);
	else
		return (r);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
