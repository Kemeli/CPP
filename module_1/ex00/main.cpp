#include "Zombie.hpp"

int	main(void)
{
	std::string	name1;
	std::string	name2;

	name1 = "Anderson";
	name2 = "Janaina";

	randomChump(name1);

	Zombie *zombie = newZombie(name2);
	zombie->announce();
	delete(zombie);
}
