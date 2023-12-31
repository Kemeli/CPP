#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain*	brain;

	public:
	Dog(void);
	Dog(const Dog& obj);
	~Dog(void);
	Dog& operator=(const Dog& obj);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
