#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N) : _size(N) {};

void Span::addNumber(int num)
{
	if(integers.size() < _size)
		integers.push_back(num);
	else
		throw std::out_of_range("the integers vector is full.");
}

std::vector<int> Span:: getIntegers()
{
	return integers;
}

int Span::shortestSpan()
{
	int					min;
	std::vector<int>	dif;

	if (integers.size() < 2)
	{
		throw std::out_of_range("vector should have two or more values!");
		return (0);
	}

	std::adjacent_difference(integers.begin(), integers.end(), std::back_inserter(dif));
	for (unsigned int i = 1; i < std::distance(dif.begin(), dif.end()); i++)
	{
		if (i == 1)
		{
			min = dif[i];
			i++;
		}
		if (dif[i] < min)
			min = dif[i];
	}
	return (min);
}

int Span::longestSpan()
{
	int					max;
	std::vector<int>	dif;

	if (integers.size() < 2)
	{
		throw std::out_of_range("vector should have two or more values!");
		return (0);
	}

	std::adjacent_difference(integers.begin(), integers.end(), std::back_inserter(dif));
	for (unsigned int i = 1; i < std::distance(dif.begin(), dif.end()); i++)
	{
		if (i == 1)
		{
			max = dif[i];
			i++;
		}
		if (dif[i] > max)
			max = dif[i];
	}
	return (max);
}

// void Span::addNumbers(int N)
// {

// 	for (int i = 0; i < n; i++)
// 		addNumber(i);
// }
