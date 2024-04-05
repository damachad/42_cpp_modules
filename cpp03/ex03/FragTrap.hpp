/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:21:26 by damachad          #+#    #+#             */
/*   Updated: 2024/04/03 15:03:06 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap(void);
		FragTrap(FragTrap const & src);
		FragTrap(std::string name);
		~FragTrap(void);

		FragTrap &  operator=(FragTrap const & src);

		void	highFivesGuys(void);

};

#endif
