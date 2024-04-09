/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:55:01 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 16:14:36 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{

	public:

		Character(void);
		Character(Character const & src);
		Character(std::string const & name);
		virtual ~Character(void);

		Character &  operator=(Character const & src);

		virtual std::string const &	getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:

		std::string 	_name;
		AMateria*		_inventory[4];
		AMateria**		_floor;
		int				_floorCount;

		void			_floorPush(AMateria* m);

};

#endif // CHARACTER_HPP
