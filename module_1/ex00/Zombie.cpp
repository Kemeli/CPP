#include "Zombie.hpp"

Zombie::Zombie(std::string	new_name)
{
	this->name = new_name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
