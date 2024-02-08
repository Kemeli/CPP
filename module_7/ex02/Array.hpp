#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		~Array();
		Array & operator=(Array const & rhs);
		T & operator[](unsigned int i) const;
		unsigned int size() const;
	private:
		T * _arr;
		unsigned int _size;
};

#include "Array.tpp"

#endif
