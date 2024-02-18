#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

class RPN {
public:
	RPN(const RPN& a);
	RPN& operator=(const RPN& a);
	~RPN();

	RPN(std::string input);

	bool setStack(std::string token);
private:
	RPN();
	std::stack<double> _stack;
	bool _validateInput(std::string input);
};

#endif
