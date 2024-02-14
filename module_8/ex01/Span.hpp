#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

# define PINK "\033[38;5;206m"
# define RESET "\033[0m"
# define BLUE "\033[38;5;27m"
# define ORANGE "\033[38;5;208m"

class Span
{
	public:
	Span(unsigned int N);
	Span(Span const &other);
	Span &operator=(Span const &other);
	~Span();

	void addNumber(int num);
	void addNumbers(
		std::vector<int>::iterator first,
		std::vector<int>::iterator last
		);
	int shortestSpan();
	int longestSpan();

	unsigned int getIntegersSize();
	void printIntegers();

	private:
	Span();
	std::vector<int> integers;
	unsigned int _size;
};

#endif
