#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat(void); //setar tipo
	Cat(const Cat& obj);
	~Cat(void);
	Cat& operator=(const Cat& obj);
	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
