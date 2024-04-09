/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:56:15 by damachad          #+#    #+#             */
/*   Updated: 2024/03/07 11:35:02 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &  operator=(Cat const & src);

		virtual void	makeSound(void) const;

};

#endif // CAT_HPP
