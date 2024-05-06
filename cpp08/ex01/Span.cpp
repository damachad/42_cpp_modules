#include "Span.hpp"

Span::Span(void) : _size(0)
{
	std::cout << "Span default constructor called." << std::endl;
}

Span::Span(unsigned int n) : _size(n)
{
	std::cout << "Span constructor called for size: " << n << std::endl;
	this->_array.reserve(n);
}

Span::Span(Span const & src)
{
	std::cout << "Copy Span constructor called.";
	*this = src;
}

Span::~Span(void)
{
	std::cout << "Span destructor called." << std::endl;
}

Span &	Span::operator=(Span const & src)
{
	this->_size = src.getSize();
	std::cout << "Assignment operator for Span of size ";
	std::cout << this->_size << std::endl;
	for (unsigned int i = 0; i < src.getSize(); i++)
		this->_array[i] = src._array[i];
	return (*this);
}

unsigned int	Span::getSize(void) const
{
	return (this->_size);
}

size_t	Span::getCapacity(void) const
{
	return (this->_array.capacity());
}

int	Span::getLastElement()
{
	return (*(this->_array.end() - 1));
}

void	Span::printArray(void) const
{
	for (std::vector<int>::const_iterator ptr = this->_array.begin(); \
	ptr < this->_array.end(); ptr++)
		std::cout << *ptr << ", ";
}

void	Span::addNumber(int n)
{
	if (this->_array.size() < getSize())
	{
		this->_array.push_back(n);
	}
	else
		throw FullArray();
}

void	Span::addRange(int min, int max)
{
	int range = abs(max - min) + 1;
	int tmp = min;
	if (min > max)
	{
		min = max;
		max = tmp;
	}
	if (min == max && this->_array.size() < getSize())
		this->_array.push_back(min);
	else if (this->_array.size() + range <= getSize())
	{
		for (int i = min; i <= max; i++)
			this->_array.push_back(i);
	}
	else
		throw FullArray();
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>	sorted(this->_array);
	int	shortestSpan = INT_MAX;
	int	smallSpan;

	std::sort(sorted.begin(), sorted.end());
	if (this->_array.empty() || this->_array.size() == 1)
		throw NoSpan();
	for (std::vector<int>::const_iterator ptr = sorted.begin(); \
	ptr != sorted.end() - 1; ptr++)
	{
		smallSpan = abs(*ptr - *(ptr + 1));
		if (smallSpan < shortestSpan)
			shortestSpan = smallSpan;
	}
	return (shortestSpan);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_array.size() <= 1)
		throw Span::NoSpan();
	std::vector<int>::const_iterator min = \
	std::min_element(this->_array.begin(), this->_array.end());
    std::vector<int>::const_iterator max = \
	std::max_element(this->_array.begin(), this->_array.end());

    return (*max - *min);
}
