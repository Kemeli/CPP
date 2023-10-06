#include "Phonebook.hpp"

int	main(void)
{
	std::string	action;
	PhoneBook	agenda;

	while (1)
	{
		std::cout << "Choose an action: ADD, SEARCH, EXIT:" << std::endl ;
		std::getline(std::cin, action);

		if (action == "ADD")
			add(agenda);
		else if (action == "SEARCH")
			agenda.search(agenda);
		else if (action == "EXIT")
			return (0);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (0);
		}
	}
}
