#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int size = 4;
	Animal *animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < (size / 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
		delete animals[i];

	std::cout << "\n--------dog deep copy--------" << std::endl;
	Dog *dog = new Dog();
	Dog *dog2 = new Dog();
	*dog2 = *dog;
	dog2->makeSound();
	delete dog;
	delete dog2;

	std::cout << "\n--------cat deep copy--------" << std::endl;
	Cat test;
	Cat test2;
	test = test2;
	test.makeSound();
}
