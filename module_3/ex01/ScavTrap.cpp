#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor was called" << std::endl;
	this->set_name("Eddie the Shipboard Computer");
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor was called" << std::endl;
	this->set_name(name);
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "Copy ScavTrap constructor was called" << std::endl;
	*this = obj;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->get_name() <<
		" is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor was called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::string	name = this->get_name();
	int			hit = this->get_hit_points();
	int			energy = this->get_energy_points();
	int			attack_damage = this->get_attack_damage();

	if (hit < 1 || energy < 1)
	{
		std::cout << "ScavTrap " << name << " coudn't attack " << std::endl;
		std::cout << "\t" << name << " hit points is " << hit << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target <<
		" causing " << attack_damage << " points of damage! " << std::endl;
		this->set_energy_points(energy - 1);
	}
	std::cout << "\t" << name << " energy points is " << get_energy_points()
		<< std::endl;
}
