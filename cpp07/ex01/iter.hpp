/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:22:57 by damachad          #+#    #+#             */
/*   Updated: 2024/04/24 12:29:47 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename F>
void iter(T *array, size_t size, F func)
{
	for (size_t i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

template<typename T>
void printElement(T const & element)
{
	std::cout << element << ' ';
}

#endif
