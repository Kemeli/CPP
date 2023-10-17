#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
	std::string	name;

	public:
	Zombie(std::string	new_name);
	~Zombie();
	void	announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);


#endif
