/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:30:49 by damachad          #+#    #+#             */
/*   Updated: 2024/04/08 12:40:51 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{

	public:

		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain &  operator=(Brain const & src);

		void	printIdeas(void);
		void	printIdeaIndex(int i);
		void	setIdea(std::string idea);
		void	cloneIdeas(Brain const & src);

	private:
		std::string	_ideas[100];

};

#endif // BRAIN_HPP
