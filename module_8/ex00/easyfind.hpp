#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
unsigned int easyfind(T & container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return std::distance(container.begin(), it);
	else
		throw std::out_of_range("value not found.");
}

#endif
