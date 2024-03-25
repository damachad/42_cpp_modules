/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:39 by damachad          #+#    #+#             */
/*   Updated: 2024/03/25 10:20:23 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
	public:
		void	announce(void);
		void	setName(std::string name);

		Zombie(void);
		~Zombie(void);
	
	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif