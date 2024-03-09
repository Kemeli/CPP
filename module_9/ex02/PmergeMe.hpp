#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <sys/time.h>

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& a);
	PmergeMe& operator=(const PmergeMe& a);

	template <typename Container>
	void processInputAndSort(Container& container, char* argv[], int argc, std::string type);

	template <typename Container>
	void displayResults(Container& data);

private:
	template <typename Container>
	void fordJohnsonSort(Container& container, int left, int right);

	template <typename Container>
	void merge(Container& container, int left, int middle, int right);

	template <typename Container>
	void displayFinalTime(struct timeval &start, Container &container, std::string type);

	template <typename Container>
	void fillContainer(Container& container, char* argv[], int argc);
};

#include "PmergeMe.tpp"

#endif
