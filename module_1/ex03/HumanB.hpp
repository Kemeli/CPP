#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
	Weapon *weapon;
	std::string name;

	public:
	void attack();
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);
	void setWeapon(Weapon *weapon);
};

#endif
