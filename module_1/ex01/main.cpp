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

	std::cout << "Choose an action: ADD, SEARCH, EXIT: ";
	std::cin >> action;

	if (action == "ADD")
	{
		std::cout << "Enter firt name: " << std::endl;
		std::cin >> first_n;
		std::cout << "Enter last name: " << std::endl;
		std::cin >> last_n;
		std::cout << "Enter nickname: " << std::endl;
		std::cin >> nick_n;
		std::cout << "Enter phone_number: " << std::endl;
		std::cin >> phone_num;
		std::cout << "Enter darkest_secret: " << std::endl;
		std::cin >> darkest_secret;
		agenda.addContact(Contact(first_n, last_n, nick_n, phone_num, darkest_secret));
	}
	else if (action == "SEARCH")
		std::cout << "you chose " + action;
	else if (action == "EXIT")
		std::cout << "you chose " + action;
	else
		std::cout << "Invalid action, run the program again" << std::endl;
}
