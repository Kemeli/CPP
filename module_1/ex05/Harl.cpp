#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << " DEBUG\nI love having extra bacon for my "
	"'7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO\nI cannot believe adding extra bacon costs more money. "
	"You didn't put enough bacon in my burger! If you did, I wouldn't "
	"be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING\nI think I deserve to have some extra bacon for free."
	" I've been coming for years whereas you started working here "
	"since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR\nThis is unacceptable! "
	"I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int i;

	i = 0;
	std::string levels[4] = {"INFO", "WARNING", "ERROR", "DEBUG"};

	void (Harl::*MemFuncPtr[4])(void) =
			{&Harl::info, &Harl::warning, &Harl::error, &Harl::debug};

	while (levels[i] != level)
		i++;
	if (i <= 3)
		(this->*MemFuncPtr[i])();
	else
		std::cout << "Invalid complain!" << std::endl;
}
