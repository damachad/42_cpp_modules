/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:29:02 by damachad          #+#    #+#             */
/*   Updated: 2024/04/29 13:05:33 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>

class NotFound : public std::exception
{
	public:
		virtual const char *what() const throw(){
			return "Element not found";
		};
};

template<typename T>
typename T::value_type	easyfind(T cont, int n)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	
	if (it != cont.end())
		return (*it);
	throw NotFound();
}

#endif
