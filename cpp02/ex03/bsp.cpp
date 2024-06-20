/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:05:12 by damachad          #+#    #+#             */
/*   Updated: 2024/06/20 13:05:53 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool    repeated(Point const a, Point const b, Point const c)
{
	bool    ab = (a.getX() == b.getX() && a.getY() == b.getY());
	bool    ac = (a.getX() == c.getX() && a.getY() == c.getY());
	bool    bc = (b.getX() == c.getX() && b.getY() == c.getY());
	
	if (ab || ac || bc)
		return true;
	return false;
}

Fixed crossProduct(const Point &A, const Point &B, const Point &P)
{
	Fixed ABx = B.getX() - A.getX();
	Fixed ABy = B.getY() - A.getY();
	Fixed APx = P.getX() - A.getX();
	Fixed APy = P.getY() - A.getY();
	
	return (ABx * APy - ABy * APx);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// valid triangle check
	if (repeated(a, b, c))
		return false;

	Fixed cpABP = crossProduct(a, b, point);
	Fixed cpBCP = crossProduct(b, c, point);
	Fixed cpCAP = crossProduct(c, a, point);

	// point on edge or vertex
	if (cpABP == 0 || cpBCP == 0 || cpCAP == 0)
		return false;
	// point on same side of line
	if ((cpABP > 0 && cpBCP > 0 && cpCAP > 0) || \
	(cpABP < 0 && cpBCP < 0 && cpCAP < 0))
		return true;
	return false;
}
