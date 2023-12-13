#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << YELLOW << "Dog constructor called" << RESET_COLOR << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << YELLOW << "Dog copy constructor called" << RESET_COLOR << std::endl;
	*this = obj;
}

void	Dog::makeSound(void) const
{
	std::cout << "Au Au" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << YELLOW << "Dog destructor called" << RESET_COLOR << std::endl;
	delete this->brain;
}

std::string	Dog::getType(void) const
{
	return (this->type);
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << YELLOW << "Dog copy operator called" << RESET_COLOR << std::endl;
	if (this == &obj)
		return (*this);
	this->type = obj.type;
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}
