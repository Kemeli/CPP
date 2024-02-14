#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

#define RESET "\033[0m"
#define PINK "\033[38;5;206m"
#define BLUE "\033[38;5;27m"

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &src) : std::stack<T>(src) {}
	~MutantStack() {}

	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->::c.begin(); }
	iterator end() { return this->::c.end(); }
};

#endif
