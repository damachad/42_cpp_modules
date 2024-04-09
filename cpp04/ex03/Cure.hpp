/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:55:06 by damachad          #+#    #+#             */
/*   Updated: 2024/03/08 14:03:46 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{

	public:

		Cure(void);
		Cure(Cure const & src);
		~Cure(void);

		Cure &  operator=(Cure const & src);

		virtual Cure*	clone(void) const;

};

#endif // CURE_HPP
