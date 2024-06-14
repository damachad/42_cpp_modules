/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:01:49 by damachad          #+#    #+#             */
/*   Updated: 2024/06/13 15:11:49 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void)
{}

PmergeMe &	PmergeMe::operator=(PmergeMe const & src)
{
	if (this != &src)
	{
		_sortList = src._sortList;
		_sortVector = src._sortVector;
		_auxList = src._auxList;
		_auxVector = src._auxVector;
	}
	return (*this);
}

bool	PmergeMe::isValidNumber(std::string number)
{
	if (number.empty())
		return (false);
	for (size_t i = 0; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
			return (false);
	}
	long n = std::atol(number.c_str());
	if (n > INT_MAX)
		return (false);
	return (true);
}

bool	PmergeMe::parseInput(char **args)
{
	for (int i = 1; args[i]; i++)
	{
		if (!isValidNumber(args[i]))
			return (false);
		_sortVector.push_back(std::atoi(args[i]));
		_sortList.push_back(std::atoi(args[i]));
	}
	return (true);
}

// Vector functions

void	PmergeMe::printVector()
{
	for (size_t i = 0; i < _sortVector.size(); i++)
	{
		std::cout << _sortVector[i] << ' ';
	}
	std::cout << '\n';
}

void	PmergeMe::printAuxVector()
{
	std::cout << "AuxVector (" << _auxVector.size() << " pairs): ";
	for (size_t i = 0; i < _auxVector.size(); i++)
	{
		std::cout << "[ " << _auxVector[i][0] << ", " << _auxVector[i][1] << " ] ";
	}
	std::cout << '\n';
}

// Recursive function to generate nth Jacobsthal number
int	jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

// Build a sequence of valid Jacobsthal numbers given an array length
std::vector<int>	buildJacobInsertionSequence(const std::vector<int>& pend)
{
	int length = pend.size();
	std::vector<int> jSequence;
	int jacobsthalIndex = 3; // The first one that matters

	while (jacobsthal(jacobsthalIndex) <= length)
	{
		jSequence.push_back(jacobsthal(jacobsthalIndex));
		jacobsthalIndex++;
	}
	return (jSequence);
}

std::vector<int> PmergeMe::createSPendVector()
{
	_sortVector.clear();
	std::vector<int> & S = _sortVector;
	std::vector<int> pend;

	for (size_t i = 0; i < _auxVector.size(); i++) // divide pairs into S(ordered larger values) and pend(unordered lower values)
	{
		S.push_back(_auxVector[i][1]);
		pend.push_back(_auxVector[i][0]);
	}
	return (pend);
}

void	PmergeMe::insertIntoSVector(std::vector<int> pend, bool hasStraggler, int straggler)
{
	std::vector<int> & S = _sortVector;
	
	S.insert(S.begin(), pend[0]); // insert first element from pend into S
	std::vector<int> jacobInsertionSequence = buildJacobInsertionSequence(pend);
	std::vector<int> indexSequence;
	indexSequence.push_back(1); // first pend element was already added
	bool jacobTurn = true;
	int lastJacob = 0;

	for (size_t insertions = 1; insertions <= pend.size(); insertions++)
	{
		int item = 0;
		if (!jacobInsertionSequence.empty() && jacobTurn)
		{
			indexSequence.push_back(jacobInsertionSequence[0]);
			item = pend[jacobInsertionSequence[0] - 1];
			lastJacob = jacobInsertionSequence[0];
			jacobInsertionSequence.erase(jacobInsertionSequence.begin());
			jacobTurn = false;
		}
		else
		{
			if (std::find(indexSequence.begin(), indexSequence.end(), insertions) != indexSequence.end())
				insertions++;
			if (insertions > pend.size())
				break ;
			item = pend[insertions - 1];
			indexSequence.push_back(insertions);
			if (lastJacob == (static_cast<int>(insertions) + 1))
				jacobTurn = true;
		}
		// std::cout << "Inserting index: " << indexSequence.back() << "\n";
		std::vector<int>::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), item);
		S.insert(insertionPoint, item);
	}
	if (hasStraggler)
	{
		std::vector<int>::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), straggler);
		S.insert(insertionPoint, straggler);
	}
}

// Utility function for recursive insertion sort by highest value in pair
void insertInSequenceVector(std::vector<std::vector<int> >& A, const std::vector<int> currPair, int n)
{
	if (n >= 0 && A[n][1] > currPair[1]) // if this pair has a larger value than the currPair (being inserted)
	{
		A[n + 1] = A[n]; // shift this pair to the right
		insertInSequenceVector(A, currPair, n - 1); // check pair to the left
	}
	else
		A[n + 1] = currPair; // inserts the currPair in its place in the sequence of pairs
}

// Recursive function to sort pairs by their higher value
void	PmergeMe::sortByLargerValueVector(std::vector<std::vector<int> >& auxV, int n)
{
	if (n <= 1)
		return;
	else
	{
		sortByLargerValueVector(auxV, n - 1); // recursion to evaluate each element of array
		insertInSequenceVector(auxV, auxV[n - 1], n - 2); // insert pair 'n - 1' in the sorted sequence up to index 'n - 1'
	}
}

void	PmergeMe::sortEachPairVector()
{
	for (size_t i = 0; i < _auxVector.size(); i++)
	{
		std::vector<int>& pair = _auxVector[i];
		if (pair[0] > pair[1])
			std::swap(pair[0], pair[1]);
	}
}

void	PmergeMe::createPairsVector()
{
	std::vector<int> tempArray;

	for (size_t i = 0; i < _sortVector.size(); i++)
	{
		int value = _sortVector[i];
		size_t temp_length = tempArray.size();

		if (temp_length == 1)
		{
			tempArray.push_back(value);
			_auxVector.push_back(tempArray);
			tempArray.clear();
		}
		else if (temp_length == 0)
			tempArray.push_back(value);
	}
}

void	PmergeMe::mergeInsertSortVector()
{
	bool	hasStraggler = _sortVector.size() % 2 != 0;
	int		straggler = -1;

	if (hasStraggler)
	{
		straggler = _sortVector.back();
		_sortVector.pop_back();
	}
	createPairsVector();
	sortEachPairVector();
	sortByLargerValueVector(_auxVector, _auxVector.size());
	insertIntoSVector(createSPendVector(), hasStraggler, straggler);
}

// List functions

void	PmergeMe::printList()
{
	std::list<int>::iterator it;
	for (it = _sortList.begin(); it != _sortList.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << '\n';
}

void	PmergeMe::printAuxList()
{
	std::list< std::list<int> >::iterator it;
	std::cout << "AuxList (" << _auxList.size() << " pairs): ";
	for (it = _auxList.begin(); it != _auxList.end(); it++)
	{
		std::list<int>::iterator element = it->begin();
		std::cout << "[ " << *element << ", " << *++element << " ] ";
	}
	std::cout << '\n';
}

std::list<int>	buildJacobInsertionSequence(const std::list<int>& pend)
{
	int length = pend.size();
	std::list<int> jSequence;
	int jacobsthalIndex = 3; // The first one that matters

	while (jacobsthal(jacobsthalIndex) <= length)
	{
		jSequence.push_back(jacobsthal(jacobsthalIndex));
		jacobsthalIndex++;
	}
	return (jSequence);
}

std::list<int> PmergeMe::createSPendList()
{
	_sortList.clear();
	std::list<int> & S = _sortList;
	std::list<int> pend;

	std::list< std::list<int> >::iterator it;
	for (it = _auxList.begin(); it != _auxList.end(); it++) // divide pairs into S(ordered larger values) and pend(unordered lower values)
	{
		std::list<int>::iterator first = it->begin();
		std::list<int>::iterator second = first;
		++second;
		S.push_back(*second);
		pend.push_back(*first);
	}
	return (pend);
}

void	PmergeMe::insertIntoSList(std::list<int> pend, bool hasStraggler, int straggler)
{
	std::list<int> & S = _sortList;
	
	S.insert(S.begin(), pend.front()); // insert first element from pend into S
	std::list<int> jacobInsertionSequence = buildJacobInsertionSequence(pend);
	std::list<int> indexSequence;
	indexSequence.push_back(1); // first pend element was already added
	bool jacobTurn = true;
	int lastJacob = 0;

	for (size_t insertions = 1; insertions <= pend.size(); insertions++)
	{
		std::list<int>::iterator it = pend.begin();
		int item = 0;
		if (!jacobInsertionSequence.empty() && jacobTurn)
		{
			int jacobIndex = jacobInsertionSequence.front();
			indexSequence.push_back(jacobIndex);
			std::advance(it, jacobIndex - 1);
			item = *it;
			lastJacob = jacobIndex;
			jacobInsertionSequence.pop_front();
			jacobTurn = false;
		}
		else
		{
			if (std::find(indexSequence.begin(), indexSequence.end(), insertions) != indexSequence.end())
				insertions++;
			if (insertions > pend.size())
				break ;
			std::advance(it, insertions - 1);
			item = *it;
			indexSequence.push_back(insertions);
			if (lastJacob == (static_cast<int>(insertions) + 1))
				jacobTurn = true;
		}
		// std::cout << "Inserting index: " << indexSequence.back() << "\n";
		std::list<int>::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), item);
		S.insert(insertionPoint, item);
	}
	if (hasStraggler)
	{
		std::list<int>::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), straggler);
		S.insert(insertionPoint, straggler);
	}
}

void insertInSequenceList(std::list< std::list<int> >& A, std::list<int> currPair, int n)
{
	if (n < 0)
	{
		A.pop_front();
		A.push_front(currPair);
		return;
	}
	
	std::list< std::list<int> >::iterator it = A.begin();
	std::advance(it, n);
	std::list< std::list<int> >::iterator next = it;
	++next;
	
	std::list<int>::iterator element = it->begin();
	++element;
	std::list<int>::const_iterator currElem = currPair.begin();
	++currElem;
	if (*element > *currElem) // if this pair has a larger value than the currPair (being inserted)
	{
		if (next == A.end())
			A.push_back(*it);
		else
			*next = *it; // shift this pair to the right
		insertInSequenceList(A, currPair, n - 1); // check pair to the left
	}
	else
	{
		if (next == A.end())
			A.push_back(currPair);
		else
			*next = currPair; // inserts the currPair in its place in the sequence of pairs
	}
}

// Recursive function to sort pairs by their higher value
void PmergeMe::sortByLargerValueList(std::list< std::list<int> >& auxL, int n)
{
	if (n <= 1)
		return;

	sortByLargerValueList(auxL, n - 1); // recursion to evaluate each element of array

	std::list< std::list<int> >::iterator it = auxL.begin();
	std::advance(it, n - 1);
	
	// Insert the current pair in the sorted part of the list
	insertInSequenceList(auxL, *it, n - 2);
}


void	PmergeMe::sortEachPairList()
{
	std::list< std::list<int> >::iterator it;
	for (it = _auxList.begin(); it != _auxList.end(); it++)
	{
		std::list<int>::iterator first = it->begin();
		std::list<int>::iterator second = first;
		++second;
		if (*first > *second)
			std::swap(*first, *second);
	}
}

void	PmergeMe::createPairsList()
{
	std::list<int> tempArray;

	std::list<int>::iterator it;
	for (it = _sortList.begin(); it != _sortList.end(); it++)
	{
		int value = *it;
		size_t temp_length = tempArray.size();

		if (temp_length == 1)
		{
			tempArray.push_back(value);
			_auxList.push_back(tempArray);
			tempArray.clear();
		}
		else if (temp_length == 0)
			tempArray.push_back(value);
	}
}

void	PmergeMe::mergeInsertSortList()
{
	bool	hasStraggler = _sortList.size() % 2 != 0;
	int		straggler = -1;

	if (hasStraggler)
	{
		straggler = _sortList.back();
		_sortList.pop_back();
	}
	createPairsList();
	sortEachPairList();
	sortByLargerValueList(_auxList, _auxList.size());
	insertIntoSList(createSPendList(), hasStraggler, straggler);
}

void	PmergeMe::sortSequence()
{
	std::clock_t start = std::clock();
	mergeInsertSortVector();
	std::clock_t end = std::clock();
	double elapsedUsVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = std::clock();
	mergeInsertSortList();
	end = std::clock();
	double elapsedUsList = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "After: ";
	printVector();
	// printList();
	
	std::cout << "Time to process a range of " << _sortVector.size();
	std::cout << " elements with std::vector " << elapsedUsVector << " us\n";
	std::cout << "Time to process a range of " << _sortVector.size();
	std::cout << " elements with std::list " << elapsedUsList << " us\n";
}

