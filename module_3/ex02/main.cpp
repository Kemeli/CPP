#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::string	name;

	FragTrap ft;
	ScavTrap st;
	// FragTrap ft("Eddie the Shipboard Computer");
	// ScavTrap st("Marvin");


	std::cout << "\n\tGo!\n" << std::endl;

	ft.highFivesGuys();

	st.attack(ft.get_name());
	ft.takeDamage(st.get_attack_damage());

	ft.attack(st.get_name());
	st.takeDamage(ft.get_attack_damage());

	ft.beRepaired(10);
	st.guardGate();

	std::cout << ft.get_name()
			<< " merged with Hactar and was never seen again." << std::endl;

	std::cout << "\n\tThe end!\n" << std::endl;
}
