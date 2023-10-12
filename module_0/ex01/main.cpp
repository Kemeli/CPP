#include "PhoneBook.hpp"

int	main(void)
{
	std::string	action;
	PhoneBook	agenda;

	while (action != "EXIT")
	{
		std::cout << "Choose an action: ADD, SEARCH, EXIT:" << std::endl ;
		std::getline(std::cin, action);

		if (action == "ADD")
			add(agenda);
		else if (action == "SEARCH")
			agenda.search(agenda);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (0);
		}
	}
}
