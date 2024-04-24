#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{

	private:

		unsigned int	_size;
		T 				*_array;

	public:

		Array(void) : _size(0)
		{
			std::cout << "Default Array constructor" << std::endl;
			_array = new T[this->_size];
		}

		Array(unsigned int n) : _size(n)
		{
			std::cout << "Array constructor for size ";
			std::cout << this->_size << std::endl;
			_array = new T[n];
		}

		Array(Array const & src) : _size(src.size())
		{
			std::cout << "Copy Array constructor of size ";
			std::cout << this->_size << std::endl;
			this->_array = new T[src.size()];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}

		~Array(void)
		{
			std::cout << "Destroying Array of size ";
			std::cout << this->_size << std::endl;
			if (this->_array)
				delete [] this->_array;
		}

		Array &  operator=(Array const & src)
		{
			this->_size = src.size();
			std::cout << "Assignment operator for Array of size ";
			std::cout << this->_size << std::endl;
			if (this->_array)
				delete [] this->_array;
			this->_array = new T[src.size()];
			for (unsigned int i = 0; i < src.size(); i++)
				this->_array[i] = src._array[i];
			return (*this);
		}

		unsigned int	size(void) const
		{
			return (this->_size);
		}

		T &	operator[](unsigned int pos)
		{
			if (pos >= this->_size || this->_array == NULL)
			{
				std::cout << "Unable to access array at index: ";
				std::cout << pos << ". ";
				throw OutOfBounds();
			}
			return (this->_array[pos]);
		}

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char *what() const throw(){
					return "Out of bounds.";
				};
		};

};

#endif // ARRAY_HPP
