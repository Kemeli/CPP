#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << PINK << "Brain constructor called" << RESET_COLOR << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << PINK << "Brain copy constructor called" << RESET_COLOR << std::endl;
	*this = obj;
}

Brain::~Brain(void)
{
	std::cout << PINK << "Brain destructor called" << RESET_COLOR << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << PINK << "Brain copy operator called" << RESET_COLOR << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return (*this);
}
