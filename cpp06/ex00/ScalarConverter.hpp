/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:40:00 by damachad          #+#    #+#             */
/*   Updated: 2024/04/22 13:18:52 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <limits>
# include <string>
# include <cstdlib>
# include <cmath>

enum inputs
{
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{

	private:

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);

		ScalarConverter &  operator=(ScalarConverter const & src);

	public:

		static void	converter(std::string const & input);

};

#endif // SCALARCONVERTER_HPP
