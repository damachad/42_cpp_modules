/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:51:31 by damachad          #+#    #+#             */
/*   Updated: 2024/03/18 15:47:49 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	public:
		
		Contact(void);
		~Contact(void);

		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();

		void	set_first_name(std::string);
		void	set_last_name(std::string);
		void	set_nickname(std::string);
		void	set_phone_number(std::string);
		void	set_darkest_secret(std::string);
	
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

};

#endif
