/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:41:17 by damachad          #+#    #+#             */
/*   Updated: 2024/04/03 15:03:01 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	
	public:

		ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		ScavTrap(std::string name);
		ScavTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int attack);
		~ScavTrap(void);

	ScavTrap & operator=(ScavTrap const & src);

		void	attack(const std::string & target);
		void	guardGate(void);
	
};

#endif
