/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:56:15 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:59:09 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{

	public:

		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &  operator=(Cat const & src);

		virtual void	makeSound(void) const;
		Brain*	getBrain(void) const;

	private:

		Brain*	_brain;

};

#endif // CAT_HPP
