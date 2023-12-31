#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
	Brain*	brain;

	public:
	Cat(void);
	Cat(const Cat& obj);
	~Cat(void);
	Cat& operator=(const Cat& obj);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
