#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: pass ONE expression to the program" << std::endl;
		return 1;
	}
	RPN rpn(argv[1]);
	return 0;
}
