/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:31:11 by damachad          #+#    #+#             */
/*   Updated: 2024/04/02 15:12:44 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed{
	
	public:
	
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed(void);
		
		Fixed &	operator=(Fixed const & src);

		// Arithmetic
		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;
		Fixed	operator/(Fixed const & rhs) const;

		// Comparison
		bool	operator>(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;

		// Increment/decrement
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);
		
		static Fixed &	min(Fixed & l, Fixed & r);
		static Fixed const &	min(Fixed const & l, Fixed const & r);
		static Fixed &	max(Fixed & l, Fixed & r);
		static Fixed const &	max(Fixed const & l, Fixed const & r);
		
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
	
		int					_n;
		static const int	_fbits = 8;
		
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
