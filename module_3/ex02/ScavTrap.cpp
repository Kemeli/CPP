#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor was called" << std::endl;
	this->name = "Marvin";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor was called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "Copy ScavTrap constructor was called" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor was called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.get_name();
		this->hit_points = obj.get_hit_points();
		this->attack_damage = obj.get_attack_damage();
		this->energy_points = obj.get_energy_points();
	}
	return *this; //returns this dereferenced, the real content
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->get_name() <<
		" is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{

	if (this->hit_points < 1 || energy_points < 1)
	{
		std::cout << "ScavTrap " << this->name << " coudn't attack " << std::endl;
		std::cout << "\t" << this->name << " hit points is " << this->hit_points << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target <<
		" causing " << attack_damage << " points of damage! " << std::endl;
		this->energy_points--;
	}
	std::cout << "\t" << this->name << " energy points is " << this->energy_points
		<< std::endl;
}
