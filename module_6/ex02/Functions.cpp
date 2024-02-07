#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	srand(time(NULL));
	int randomNum = rand() % 3;

	switch (randomNum) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "The object is A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "The object is B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "The object is C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "The object is A" << std::endl;
		return ;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "The object is B" << std::endl;
		return ;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "The object is C" << std::endl;
		return ;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
}
