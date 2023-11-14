#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <ostream>
# include <iostream>

class ClapTrap
{
	private:
	std::string	name;
	int			energy_points;
	int			hit_points;
	int			attack_damage;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap&	operator=(const ClapTrap& obj);

	std::string	get_name() const;
	int			get_hit_points() const;
	int			get_energy_points() const;
	int			get_attack_damage() const;
};

std::ostream& operator<<(std::ostream out, const ClapTrap& obj);

#endif
