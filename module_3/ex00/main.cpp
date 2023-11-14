#include "ClapTrap.hpp"

int	main()
{
	std::string	name;

	std::cout << std::endl;

	ClapTrap robot1("Ford");
	ClapTrap robot2;

	std::cout << "\n\tGo!\n" << std::endl;

	robot1.attack(robot2.get_name());
	robot2.takeDamage(robot1.get_attack_damage());

	robot2.attack(robot1.get_name());
	robot1.takeDamage(robot2.get_attack_damage());

	robot2.beRepaired(10);

	std::cout << robot1.get_name()
			<< " got in Heart of Gold and was never seen again." << std::endl;

	std::cout << "\n\tThe end!\n" << std::endl;
}
