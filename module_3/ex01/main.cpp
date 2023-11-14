#include "ScavTrap.hpp"

int	main()
{
	std::string	name;

	ClapTrap arthur("Arthur");
	ScavTrap ford("Ford");

	std::cout << "\n\tGo!\n" << std::endl;

	arthur.attack(ford.get_name());
	ford.takeDamage(arthur.get_attack_damage());

	ford.attack(arthur.get_name());
	arthur.takeDamage(ford.get_attack_damage());

	arthur.beRepaired(10);
	ford.guardGate();

	std::cout << arthur.get_name()
			<< " went to Magrathea and was never seen again." << std::endl;

	std::cout << "\n\tThe end!\n" << std::endl;
}
