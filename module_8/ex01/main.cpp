#include "Span.hpp"

void printShortesLongestSpans(Span &span)
{
	try
	{
		int min = span.shortestSpan();
		std::cout << BLUE << "min: "<< RESET  << min << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << RESET << '\n';
	}
	try
	{
		int max = span.longestSpan();
		std::cout << BLUE << "max: "<< RESET  << max << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << RESET << '\n';
	}
}

int main()
{
	unsigned int i;

	{
		std::cout << PINK << "------ADD NUMBER!------" << RESET << std::endl;
		Span span(3);
		span.addNumber(1);
		span.addNumber(10);
		span.addNumber(12);
		span.printIntegers();
	}

	{
		std::cout << PINK << "\n------CANNOT ADD NUMBER!------" << RESET << std::endl;
		try
		{
			Span span(3);
			span.addNumber(1);
			span.addNumber(10);
			span.addNumber(12);
			span.addNumber(13);
		}
		catch(const std::exception& e)
		{
			std::cerr << ORANGE << e.what() << RESET << '\n';
		}
	}

	{
		std::cout << PINK << "\n------ADD NUMBERS------" << RESET << std::endl;
		Span span(10);
		std::vector<int> numbers;
		try
		{
			srand(time(NULL));
			for (i = 0; i < 10; i++)
			{
				int value = rand() % 20;
				numbers.push_back(value);
			}
			span.addNumbers(numbers.begin(), numbers.end());
			span.printIntegers();
		}
		catch(const std::exception& e)
		{
			std::cerr << ORANGE << e.what() << RESET << '\n';
		}
	}

	{
		std::cout << PINK << "\n------CANNOT ADD NUMBERS!------" << RESET << std::endl;
		try
		{
			Span span(3);
			std::vector<int> numbers;
			numbers.push_back(1);
			numbers.push_back(10);
			numbers.push_back(12);
			numbers.push_back(13);
			span.addNumbers(numbers.begin(), numbers.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << ORANGE << e.what() << RESET << '\n';
		}
	}

	{
		std::cout << PINK << "\n------SHORTEST AND LONGEST SPAN!------" << RESET << std::endl;

		Span span(10);
		std::vector<int> numbers;
		srand(time(NULL));
		for (i = 0; i < 10; i++)
		{
			int value = rand() % 20;
			numbers.push_back(value);
		}
		span.addNumbers(numbers.begin(), numbers.end());
		span.printIntegers();
		printShortesLongestSpans(span);
	}

	{
		std::cout << PINK << "\n------CONTROLED SHORTEST AND LONGEST SPAN!------" << RESET << std::endl;
		Span span(5);
		span.addNumber(1);
		span.addNumber(10);
		span.addNumber(12);
		span.addNumber(15);
		span.addNumber(20);

		span.printIntegers();
		printShortesLongestSpans(span);
	}

	{
		std::cout << PINK << "\n------INVALID VECTOR SIZE!------" << RESET << std::endl;
		Span span(3);
		span.addNumber(1);
		printShortesLongestSpans(span);
	}

	{
		std::cout << PINK << "\n------10000 NUMBERS------" << RESET << std::endl;
		Span				span(10000);
		std::vector<int>	numbers;

		srand(time(NULL));
		for (i = 0; i < 10000; i++)
		{
			int value = rand() % 10000;
			numbers.push_back(value);
		}

		span.addNumbers(numbers.begin(), numbers.end());
		// span.printIntegers();
		printShortesLongestSpans(span);
	}
}
