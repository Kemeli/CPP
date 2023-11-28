#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
	std::string type;

	public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal();

	std::string getType() const;
	WrongAnimal &operator=(const WrongAnimal &copy);
	void makeSound() const;
};

#endif
