#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N) : _size(N) {};

Span::Span(Span const &other)
{
	for(unsigned int i = 0; i < other.integers.size(); i++)
		this->integers.push_back(other.integers[i]);
	this->_size = other._size;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		for(unsigned int i = 0; i < other.integers.size(); i++)
			this->integers.push_back(other.integers[i]);
		this->_size = other._size;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int num)
{
	if(integers.size() < _size)
		integers.push_back(num);
	else
		throw std::out_of_range(
			"index out of range: integer vector can't accept more values!"
			);
}

int Span::shortestSpan()
{

	int min;
	int dif;

	if (integers.size() < 2)
	{
		throw std::runtime_error(
			"Cannot calculate longest span: vector should have two or more values!"
			);		return (0);
	}
	std::sort(integers.begin(), integers.end());
	min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < integers.size(); i++)
	{
		dif = abs(integers[i] - integers[i - 1]);
		if (dif < min)
			min = dif;
	}
	return (min);
}

int Span::longestSpan()
{
	int max;

	if (integers.size() < 2)
	{
		throw std::runtime_error(
			"Cannot calculate longest span: vector should have two or more values!"
			);
		return 0;
	}

	std::sort(integers.begin(), integers.end());
	max = integers.back() - integers.front();
	return max;
}

void Span::addNumbers(
	std::vector<int>::iterator first,
	std::vector<int>::iterator last)
{
	while (first != last)
	{
		addNumber(*first);
		first++;
	}
}

unsigned int Span::getIntegersSize()
{
	return (integers.size());
}

void Span::printIntegers()
{
	for (size_t i = 0; i < integers.size(); i++)
		std::cout << integers[i] << (i < (integers.size() - 1) ? ", " : "\n");
}
