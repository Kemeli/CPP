#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau Miau" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (this->type);
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat copy operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}
