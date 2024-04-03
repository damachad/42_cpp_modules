/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:31:11 by damachad          #+#    #+#             */
/*   Updated: 2024/03/25 14:27:37 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>


class Fixed{
	
	public:
	
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		
		Fixed &	operator=(Fixed const & src);
		
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		
	private:
	
		int					_n;
		static const int	_fraction = 8;
		
};


#endif
