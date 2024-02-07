#include "Functions.hpp"

int main()
{
	Base* obj = generate();

	identify(obj);
	identify(*obj);

	delete obj;
}
