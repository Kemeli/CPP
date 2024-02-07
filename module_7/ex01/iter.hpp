#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T * arr, size_t len, void callback(T & value))
{
	for (size_t i = 0; i < len; i++)
		callback(arr[i]);
}

template <typename T>
void printValue(T & value)
{
	std::cout << value << std::endl;
}

#endif