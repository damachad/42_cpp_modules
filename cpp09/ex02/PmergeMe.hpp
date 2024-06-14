/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:01:51 by damachad          #+#    #+#             */
/*   Updated: 2024/06/07 11:39:12 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <climits>
# include <algorithm>
# include <stdlib.h>
# include <cmath>
# include <ctime>

class PmergeMe
{

	private:

		std::list<int>			_sortList;
		std::vector<int>		_sortVector;
		std::list< std::list<int> > _auxList;
		std::vector< std::vector<int> > _auxVector;

		bool	isValidNumber(std::string number);
		
		// Vector functions
		void	createPairsVector();
		void	sortEachPairVector();
		void	sortByLargerValueVector(std::vector<std::vector<int> >& A, int n);
		void	printAuxVector();
		void	insertIntoSVector(std::vector<int> pend, bool hasStraggler, int straggler);
		std::vector<int>	createSPendVector();

		// List functions
		void	createPairsList();
		void	sortEachPairList();
		void	sortByLargerValueList(std::list<std::list<int> >& auxV, int n);
		void	printAuxList();
		void	insertIntoSList(std::list<int> pend, bool hasStraggler, int straggler);
		std::list<int>	createSPendList();

	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);

		PmergeMe &  operator=(PmergeMe const & src);

		void	printList();
		void	printVector();
		bool	parseInput(char **args);
		void	mergeInsertSortList();
		void	mergeInsertSortVector();
		void	sortSequence();

};

#endif
