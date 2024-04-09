/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:56:20 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:59:16 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{

	public:

		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &  operator=(Dog const & src);
		
		virtual void	makeSound(void) const;
		Brain*	getBrain(void) const;
	
	private:

		Brain*	_brain;
		
};

#endif // DOG_HPP
