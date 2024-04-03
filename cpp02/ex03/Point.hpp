/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:05:09 by damachad          #+#    #+#             */
/*   Updated: 2024/03/25 14:31:47 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"


class Point{

	public:

		Point(void);
		Point(float const x, float const y);
		Point(Point const & src);
		~Point(void);

		Point &	operator=(Point const & src);
		
		bool	operator==(Point const & ref) const;

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
	
		Fixed const _x;
		Fixed const _y;
		
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
