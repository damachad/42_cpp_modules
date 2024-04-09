/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:55:12 by damachad          #+#    #+#             */
/*   Updated: 2024/03/08 14:03:33 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{

	public:

		Ice(void);
		Ice(Ice const & src);
		~Ice(void);

		Ice &  operator=(Ice const & src);

		virtual Ice*	clone(void) const;

};

#endif // ICE_HPP
