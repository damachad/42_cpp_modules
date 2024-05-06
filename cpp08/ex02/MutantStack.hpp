#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template< typename T >
class MutantStack : public std::stack< T, std::deque<T> >
{

	public:

		typedef typename std::stack< T, std::deque<T> > stackDeque;
		typedef typename std::deque<T>::iterator iterator;

		MutantStack(void){};
		MutantStack(MutantStack const & src){
			*this = src;
		};
		~MutantStack(void){};

		MutantStack &  operator=(MutantStack const & src){
			stackDeque::operator=(this, src);
			return (*this);
		};

		iterator	begin()
		{
			return (this->c.begin());
		};

		iterator	end()
		{
			return (this->c.end());
		};

};

#endif
