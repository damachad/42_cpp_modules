/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:38:57 by damachad          #+#    #+#             */
/*   Updated: 2024/04/19 15:21:44 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{

	public:

		virtual ~Base(void);
		
		static Base * generate(void);
		static void identify(Base* p);
		static void identify(Base& p);

};

class A : public Base{};
class B : public Base{};
class C : public Base{};

#endif // BASE_HPP
