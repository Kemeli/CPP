#include "Span.hpp"

int main()
{
	Span span(10);
	int min;
	int max;

	// for (int i = 0; i < 10; i++)
	span.addNumber(1);
	// span.addNumber(10);
	// span.addNumber(12);
	// span.addNumber(15);
	// span.addNumber(16);

	std::vector<int> integers = span.getIntegers();
	unsigned int i;
	for (i = 0; i < std::distance(integers.begin(), integers.end()); i++)
		std::cout << integers[i] << std::endl;

	std::cout << "\n------MIN AND MAX------" << std::endl;
	try
	{
		min = span.shortestSpan();
		std::cout << "min: " << min << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		max = span.longestSpan();
		std::cout << "max: " << max << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
