#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define PINK "\033[35m"
# define YELLOW "\033[0;33m"
# define RED "\033[31m"
# define RESET_COLOR "\033[0m"

class Animal
{
	protected:
	std::string type;

	public:
	Animal(void);
	Animal(const Animal& obj);
	virtual ~Animal(void);
	Animal& operator=(const Animal& obj);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;

};

#endif
