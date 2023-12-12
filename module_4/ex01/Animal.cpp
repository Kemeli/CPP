#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

Animal& Animal::operator=(const Animal& obj)
{
	this->type = obj.type;
	return (*this);
}
