#include "Zombie.hpp"

int	main(void)
{
	int		N;
	int		i;

	N = 4;
	Zombie *zombie = zombieHorde(N, "bizum");

	i = 0;
	while(i < N)
	{
		zombie[i].announce();
		i++;
	}
	delete[] zombie;
}
