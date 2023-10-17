#include "Zombie.hpp"

Zombie::Zombie(std::string	new_name)
{
	this->name = new_name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " was destroyed" <<std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
