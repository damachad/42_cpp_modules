/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:49:59 by damachad          #+#    #+#             */
/*   Updated: 2024/06/13 13:16:23 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstring> 
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <climits>
# include <algorithm>
# include <map>

class BitcoinExchange
{

	private:

		std::map<std::string, float> dataMap;

		bool		isValidInput(std::string line);
		bool		isValidDate(std::string date);
		bool		isPositiveNumber(std::string value) const;
		bool		isInLimit(std::string value) const;
		bool		isValidValue(std::string value) const;
		void		printValues(std::string date, std::string value);
		void		removeSpaces(std::string & s);
		void		trimOuterSpaces(std::string & s);
		std::tm *	parseDateTime(const char* datetimeString, const char* format);
		bool		sameDates(std::tm * d1, std::tm * d2);
		float		getClosestDateValue(std::string date);
		long		toLongDate(std::string s);

	public:

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);

		BitcoinExchange &  operator=(BitcoinExchange const & src);

		void	loadData(std::string filename);
		void	processInput(std::string filename);
		void	printData() const;
		size_t	getMapSize() const;

};

#endif
