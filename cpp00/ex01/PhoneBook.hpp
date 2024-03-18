/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:48:43 by damachad          #+#    #+#             */
/*   Updated: 2024/03/18 14:37:51 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string.h>
# include <string>
# include <stdlib.h>
# include <limits>

class PhoneBook {
	public:	
		
		PhoneBook(void);
		~PhoneBook(void);
		
		void	add_contact(void);
		void	search_contacts(void);
	
	private:
		Contact		_contacts[8];
		int			_index;
		std::string	_add_info(std::string msg);
		bool		_check_number(std::string number);
		void		_get_contact_info(void);
		bool		_display_all;
};

#endif
