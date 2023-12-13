#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define PINK "\033[35m"
# define RESET_COLOR "\033[0m"

class Brain
{
	private:
	std::string	ideas[100];

	public:
	Brain(void);
	Brain(const Brain& obj);
	~Brain(void);
	Brain& operator=(const Brain& obj);
};

#endif
