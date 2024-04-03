/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:05:12 by damachad          #+#    #+#             */
/*   Updated: 2024/04/02 16:29:02 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool is_on_edge(const Point a, const Point b, const Point c, const Point p)
{
	bool    abp_same_x = a.getX() == b.getX() && p.getX() == a.getX();
    bool    acp_same_x = a.getX() == c.getX() && p.getX() == a.getX();
    bool    cbp_same_x = c.getX() == b.getX() && p.getX() == c.getX();
    bool    abp_same_y = a.getY() == b.getY() && p.getY() == a.getY();
    bool    acp_same_y = a.getY() == c.getY() && p.getY() == a.getY();
    bool    cbp_same_y = c.getY() == b.getY() && p.getY() == c.getY();
    
	if(abp_same_x || abp_same_y || acp_same_x || acp_same_y \
    || cbp_same_x || cbp_same_y)
		return (true);
	return(false);
}

bool    is_vertex(Point const a, Point const b, Point const c, Point const p)
{
    bool    ap = (a.getX() == p.getX() && a.getY() == p.getY());
    bool    bp = (b.getX() == p.getX() && b.getY() == p.getY());
    bool    cp = (c.getX() == p.getX() && c.getY() == p.getY());
    
    if (ap || bp || cp)
        return true;
    return false;
}

bool    repeated(Point const a, Point const b, Point const c)
{
    bool    ab = (a.getX() == b.getX() && a.getY() == b.getY());
    bool    ac = (a.getX() == c.getX() && a.getY() == c.getY());
    bool    bc = (b.getX() == c.getX() && b.getY() == c.getY());
    
    if (ab || ac || bc)
        return true;
    return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ap_x = point.getX() - a.getX();
    Fixed ap_y = point.getY() - a.getY();

    if (repeated(a, b, c) || is_vertex(a, b, c, point) || is_on_edge(a, b, c, point))
        return false;
    bool p_ab = ((b.getX() - a.getX()) * ap_y - (b.getY() - a.getY()) * ap_x) > 0;

    if (((c.getX() - a.getX()) * ap_y - (c.getY() - a.getY()) * ap_x > 0) == p_ab) 
        return false;
    if (((c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY())\
	* (point.getX() - b.getX()) > 0) != p_ab) 
        return false;
    return true;
}
