#include "Phonebook.hpp"
#include <iostream>

int	main(void)
{
	std::string	action;
	PhoneBook	agenda;
	std::string	first_n;
	std::string	last_n;
	std::string	nick_n;
	std::string	phone_num;
	std::string	darkest_secret;

	while (1)
	{
		std::cout << "Choose an action: ADD, SEARCH, EXIT: ";
		std::cin >> action;

		if (action == "ADD")
		{
			std::cout << "Enter firt name: ";
			std::cin >> first_n;
			std::cout << "Enter last name: ";
			std::cin >> last_n;
			std::cout << "Enter nickname: ";
			std::cin >> nick_n;
			std::cout << "Enter phone_number: ";
			std::cin >> phone_num;
			std::cout << "Enter darkest_secret: ";
			std::cin >> darkest_secret;
			agenda.addContact(Contact(first_n, last_n, nick_n, phone_num, darkest_secret));
		}
		else if (action == "SEARCH")
		{
			agenda.displayContacts();
		}
		else if (action == "EXIT")
			std::cout << "you chose " + action;
		else
			std::cout << "Invalid action, run the program again" << std::endl;
	}
}
