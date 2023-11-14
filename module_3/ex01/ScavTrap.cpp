#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor was called" << std::endl;
	this->name = "Eddie the Shipboard Computer";
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
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->get_name() <<
		" is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::string	name = this->name;
	int			hit = this->hit_points;

	if (!hit || !this->energy_points)
		std::cout << "ScavTrap " << name << " unsuccessfully tried to attack "
		<< target << std::endl;
	else{
		std::cout << "ScavTrap " << name << " attacks " << target << " causing "
			<< this->attack_damage << " points of damage! "<< std::endl;
		this->energy_points--;
	}
	this->print_hit_points();
	this->print_energy_points();
}
