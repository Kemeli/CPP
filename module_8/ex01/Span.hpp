#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>

class Span
{
	public:
	Span(unsigned int N);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	void addNumbers();
	std::vector<int> getIntegers();

	private:
	Span();
	std::vector<int> integers;
	unsigned int _size;


};

#endif
