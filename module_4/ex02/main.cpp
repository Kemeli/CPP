#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal error;

	Cat cat;
	Dog dog;

	std::cout << cat.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
}
