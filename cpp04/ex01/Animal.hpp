/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:56:06 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:53:36 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{

	public:

		Animal(void);
		Animal(Animal const & src);
		Animal(std::string name);
		virtual ~Animal(void);

		Animal &  operator=(Animal const & src);

		std::string			getType(void) const;
		virtual void		makeSound(void) const;

	protected:

		std::string		type;

};

#endif // ANIMAL_HPP
