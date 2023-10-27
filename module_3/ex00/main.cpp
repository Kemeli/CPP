#include "ClapTrap.hpp"

int	main()
{
	std::string	name;

	ClapTrap ford("Ford");
	ClapTrap arthur("Arthur");

	std::cout << "\n\tGo!\n" << std::endl;

	ford.attack(arthur.get_name());
	arthur.takeDamage(ford.get_attack_damage());

	arthur.attack(ford.get_name());
	ford.takeDamage(10);

	ford.attack(arthur.get_name());

	// arthur.beRepaired(10);

	// std::cout << ford.get_name()
	// 		<< " got in Heart of Gold and was never seen again." << std::endl;

	// std::cout << "\n\tThe end!\n" << std::endl;
}
