#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits.h>

class Span
{

	private:

		unsigned int		_size;
		std::vector<int>	_array;

	public:

		Span(void);
		Span(unsigned int size);
		Span(Span const & src);
		~Span(void);

		Span &  operator=(Span const & src);

		unsigned int	getSize() const;
		int				getLastElement();
		void			printArray() const;
		size_t			getCapacity(void) const;

		void			addNumber(int n);
		void			addRange(int min, int max);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

	class FullArray : public std::exception
	{
		public:
			virtual const char *what() const throw(){
				return "Span array is full";
			};
	};

	class NoSpan : public std::exception
	{
		public:
			virtual const char *what() const throw(){
				return "Not enough numbers to get span";
			};
	};

};

#endif // SPAN_HPP
