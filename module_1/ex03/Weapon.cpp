#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string Weapon::getType(void)
{
	const std::string type = this->type;
	return (type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
