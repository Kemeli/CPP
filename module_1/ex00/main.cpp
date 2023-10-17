#include "Zombie.hpp"

int	main(void)
{
	std::string	name1;
	std::string	name2;
	std::string	name3;

	name1 = "zumzum";
	randomChump(name1);

	std::cout << std::endl;

	name2 = "bizum";
	Zombie zombie2(name2);
	zombie2.announce();

	name3 = "bibi";
	Zombie *zombie3 = newZombie(name3);
	zombie3->announce();

	std::cout << std::endl;

	delete(zombie3);
}
