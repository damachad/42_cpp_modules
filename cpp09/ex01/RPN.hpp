/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:07:12 by damachad          #+#    #+#             */
/*   Updated: 2024/05/22 11:41:09 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstring>
# include <stdlib.h> 

class RPN
{

	private:

		std::stack<int>	stack;

		void	trimOuterSpaces(std::string & s);
		bool	isValidChars(std::string elements) const;
		bool	calculate(std::string elements);
		bool	doOperation(char op);

	public:

		RPN(void);
		RPN(RPN const & src);
		~RPN(void);

		RPN &  operator=(RPN const & src);

		void	parseInput(std::string elements);
};

#endif // RPN_HPP
