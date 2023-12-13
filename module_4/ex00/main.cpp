#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n---------Constructors---------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n------------Tests------------" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n---------Destructors---------" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n---------Copy---------" << std::endl;
	Animal aux = Animal();
	Animal copy(aux);
	copy.makeSound();

	std::cout << "\n---------Assignment---------" << std::endl;
	Animal assign;
	assign = aux;
	assign.makeSound();


	std::cout << "\n-----Wrong Constructors-----" << std::endl;
	const WrongAnimal* wanimal = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();

	std::cout << "\n--------Wrong Tests----------" << std::endl;
	std::cout << wanimal->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	wanimal->makeSound();
	wcat->makeSound();

	std::cout << "\n------Wrong Destructors------" << std::endl;
	delete wanimal;
	delete wcat;

	std::cout << "\n------Other Destructors------" << std::endl;
}
