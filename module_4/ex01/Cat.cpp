#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << RED << "Cat constructor called" << RESET_COLOR << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << RED <<  "Cat copy constructor called" << RESET_COLOR << std::endl;
	*this = obj;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau Miau" << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << RED <<  "Cat destructor called" << RESET_COLOR << std::endl;
}

std::string	Cat::getType(void) const
{
	return (this->type);
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << RED <<  "Cat copy operator called" << RESET_COLOR << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}
