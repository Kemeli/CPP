#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

void	Dog::makeSound(void) const
{
	std::cout << "Au Au" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (this->type);
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}
