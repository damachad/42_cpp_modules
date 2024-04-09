/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:22:47 by damachad          #+#    #+#             */
/*   Updated: 2024/03/07 11:51:13 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{

	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal(std::string name);
		virtual ~WrongAnimal(void);

		WrongAnimal &  operator=(WrongAnimal const & src);

		std::string 	getType(void) const;
		void			makeSound(void) const;

	protected:

		std::string		type;

};

#endif // WRONGANIMAL_HPP
