#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "---------Constructors---------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "------------Tests------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "---------Destructors---------" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n" << std::endl;
	std::cout << "\tCopy" << std::endl;
	Animal aux = Animal();
	Animal copy(aux);
	copy.makeSound();

	std::cout << "\n" << std::endl;
	std::cout << "\tAssignment" << std::endl;
	Animal assign;
	assign = aux;
	assign.makeSound();


	std::cout << "\n" << std::endl;
	std::cout << "-----Wrong Constructors-----" << std::endl;
	const WrongAnimal* wanimal = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();

	std::cout << "--------Wrong Tests----------" << std::endl;
	std::cout << wanimal->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	wanimal->makeSound();
	wcat->makeSound();

	std::cout << "------Wrong Destructors------" << std::endl;
	delete wanimal;
	delete wcat;
}
