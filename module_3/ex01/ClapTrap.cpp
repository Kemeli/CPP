#include "ClapTrap.hpp"

//##############################################################################
// Constructors and orthodox canonical form
//##############################################################################

ClapTrap::ClapTrap()
{
	this->name = "Robot";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout << "Constructor was called" << std::endl;
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
	if (this != &obj)
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

//##############################################################################
// Getters
//##############################################################################

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

//##############################################################################
// Gaming
//##############################################################################

void	ClapTrap::attack(const std::string& target)
{
	std::string	name = this->name;
	int			hit = this->hit_points;

	if (!hit || !this->energy_points)
		std::cout << "Claptrap " << name << " unsuccessfully tried to attack "
		<< target << std::endl;
	else{
		std::cout  << "Claptrap " << name << " attacks " << target << " causing "
					<< this->attack_damage << " points of damage! "<< std::endl;
		this->energy_points--;
	}
	this->print_hit_points();
	this->print_energy_points();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << RED << this->name << " is taken " << amount
				<< " of their hit points" << std::endl;
	this->hit_points -= amount;
	if (hit_points < 0)
		this->hit_points = 0;

	this->print_hit_points();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points && this->hit_points){
		std::cout << this->name << " was repaired in " << amount
					<< " of their hit points" << std::endl;
		this->hit_points += amount;
		this->energy_points--;
	}
	else{
		std::cout << this->name << " tried to get repaired but doesn't have " <<
			"enough energy/hit points " << std::endl;
	}
	this->print_hit_points();
	this->print_energy_points();
}

//##############################################################################
// Auxiliaries
//##############################################################################

void	ClapTrap::print_hit_points(void)
{
	std::cout << PINK << this->name << " hit points is "
		<< this->hit_points  << RESET_COLOR << std::endl;
}

void	ClapTrap::print_energy_points(void)
{
	std::cout << YELLOW << this->name << " energy points is "
		<< this->energy_points << RESET_COLOR << std::endl;
}
