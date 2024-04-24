/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:03:17 by damachad          #+#    #+#             */
/*   Updated: 2024/04/22 14:18:51 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T & x, T & y)
{
	T z = x;
	x = y;
	y = z;
}

template<typename T>
T	min(T x, T y)
{
	return ((x < y) ? x : y);
}

template<typename T>
T	max(T x, T y)
{
	return ((x > y) ? x : y);
}

#endif
