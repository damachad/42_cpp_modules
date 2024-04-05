/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:43:19 by damachad          #+#    #+#             */
/*   Updated: 2024/04/03 15:40:02 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

	public:

		DiamondTrap(void);
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		DiamondTrap &  operator=(DiamondTrap const & src);

		void	whoAmI(void);
		
		using ScavTrap::attack;

	private:

		std::string		_name;

};

#endif
