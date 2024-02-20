#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN& a) {
	_stack = a._stack;
}

RPN& RPN::operator=(const RPN& a) {
	if (this != &a) {
		this->_stack = a._stack;
	}
	return *this;
}

RPN::~RPN() { }

bool RPN::setStack(std::string token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/")
	{
		if (_stack.size() < 2)
		{
			std::cerr << "Error: not enough values in stack" << std::endl;
			return (false);
		}
		double a = _stack.top();
		_stack.pop();
		double b = _stack.top();
		_stack.pop();
		if (token == "+")
			_stack.push(a + b);
		else if (token == "-")
			_stack.push(b - a);
		else if (token == "*")
			_stack.push(a * b);
		else if (token == "/")
		{
			if (a == 0)
			{
				std::cerr << "Error: division by zero" << std::endl;
				return (false);
			}
			_stack.push(b / a);
		}
	}
	else
	{
		_stack.push(std::strtod(token.c_str(), NULL));
	}
	return (true);
}

bool RPN::_validateInput(std::string input)
{
	if (input.size() < 5)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		exit(1);
	}
	for (long unsigned int i = 0; i < input.size(); i++)
	{
		if (input[i] != ' ' &&
			input[i] != '+' &&
			input[i] != '-' &&
			input[i] != '*' &&
			input[i] != '/' &&
			(input[i] < '0' || input[i] > '9'))
		{
			std::cerr << "Error: invalid character" << std::endl;
			exit(1);
		}
	}
	return (true);
}

RPN::RPN(std::string input)
{
	if (!_validateInput(input))
		return ;
	long unsigned int i = 0;
	while (i < input.size())
	{
		std::string token;
		token = input.substr(i, input.find(' ', i) - i);
		setStack(token);
		i = i + token.size() + 1;
	}
	if (_stack.size() != 1)
		std::cerr << "Error: invalid expression" << std::endl;
	else
	{
		std::cout << _stack.top() << std::endl;
	}
}
