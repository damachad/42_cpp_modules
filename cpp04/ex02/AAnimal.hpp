/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:56:06 by damachad          #+#    #+#             */
/*   Updated: 2024/03/07 15:30:34 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{

	public:

		AAnimal(void);
		AAnimal(AAnimal const & src);
		AAnimal(std::string name);
		virtual ~AAnimal(void);

		AAnimal &  operator=(AAnimal const & src);

		std::string			getType(void) const;
		virtual void		makeSound(void) const = 0;

	protected:

		std::string		type;

};

#endif // ANIMAL_HPP
