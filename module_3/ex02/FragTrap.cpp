#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor was called" << std::endl;
	this->name = "Eddie the Shipboard Computer";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor was called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	std::cout << "Copy FragTrap constructor was called" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor was called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->get_name() <<
		" asks: High five for hitchhiking the galaxy?." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	std::string	name = this->name;
	int			hit = this->hit_points;

	if (!hit || !this->energy_points)
		std::cout << "FragTrap " << name << " unsuccessfully tried to attack "
		<< target << std::endl;
	else{
		std::cout << "FragTrap " << name << " attacks " << target << " causing "
			<< this->attack_damage << " points of damage! "<< std::endl;
		this->energy_points--;
	}
	this->print_hit_points();
	this->print_energy_points();
}
