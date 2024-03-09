#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& a)
{
	(void) a;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& a)
{
	(void) a;
	return (*this);
}