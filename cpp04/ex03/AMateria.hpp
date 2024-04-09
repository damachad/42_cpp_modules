/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:54:55 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 13:56:00 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	protected:
		std::string	type;

	public:

		AMateria(void);
		AMateria(AMateria const & src);
		AMateria(std::string const & type);
		virtual ~AMateria(void);

		AMateria &	operator=(AMateria const & src);
				
		std::string const &	getType(void);
		
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

};

#endif // AMATERIA_HPP
