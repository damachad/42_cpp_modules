/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:10:59 by damachad          #+#    #+#             */
/*   Updated: 2024/04/19 14:30:33 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	int		i;
	char	c;
};

class Serializer
{

	private:

		Serializer(void);
		Serializer(Serializer const & src);
		~Serializer(void);

		Serializer &  operator=(Serializer const & src);

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif // SERIALIZER_HPP
