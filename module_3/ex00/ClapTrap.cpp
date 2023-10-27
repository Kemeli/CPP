#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Marvin";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout << "Named constructor was called" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy constructor was called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj) //compare this to the adress of obj, 'cause "this" is a pointer
	{
		this->name = obj.get_name();
		this->hit_points = obj.get_hit_points();
		this->energy_points = obj.get_energy_points();
		this->attack_damage = obj.get_attack_damage();
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor was called" << std::endl;
}

std::string ClapTrap::get_name() const
{
	return this->name;
}

int ClapTrap::get_hit_points() const
{
	return this->hit_points;
}

int ClapTrap::get_energy_points() const
{
	return this->energy_points;
}

int ClapTrap::get_attack_damage() const
{
	return this->attack_damage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points < 1 || this->energy_points < 1)
	{
		std:: cout << this->name << " couldn't attack " << std::endl;
		std::cout << "\t" << this->name << " hit points is "
			<< this->hit_points << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks " << target
				<< " causing " << this->attack_damage << " points of damage! "
				<< std::endl;
		this->energy_points--;
	}
	std::cout << "\t" << this->name << " energy points is "
			<< this->energy_points << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name << " is taken " << amount
		<< " of their hit points" << std::endl;
	this->hit_points -= amount;

	std::cout << "\t" << this->name << " hit points is "
		<< this->hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->name << " was repaired in " << amount
			<< " of hit points" << std::endl;
	this->hit_points += amount;
	this->energy_points--;

	std::cout << "\t"  << this->name << " hit points is "
		<< this->hit_points << std::endl;

	std::cout << "\t" << this->name << " energy points is "
		<< this->energy_points << std::endl;
}
