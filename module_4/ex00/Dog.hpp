#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog(void);
	~Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
