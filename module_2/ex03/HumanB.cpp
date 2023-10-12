#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name <<
			" attacks with their bare hands" << std::endl;
	else
		std::cout << this->name <<
			" attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}
