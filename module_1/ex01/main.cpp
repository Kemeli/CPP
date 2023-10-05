#include "Phonebook.hpp"
#include <iostream>

void	add(PhoneBook &agenda)
{
	std::string	first_n;
	std::string	last_n;
	std::string	nick_n;
	std::string	phone_num;
	std::string	darkest_secret;

	while (first_n.empty()){
		std::cout << "Enter firt name: ";
		std::getline(std::cin, first_n);
	}
	while (last_n.empty()){
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_n);
	}
	while (nick_n.empty()){
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nick_n);
	}
	while (phone_num.empty()){
		std::cout << "Enter phone_number: ";
		std::getline(std::cin, phone_num);
	}
	while (darkest_secret.empty()){
		std::cout << "Enter darkest_secret: ";
		std::getline(std::cin, darkest_secret);
	}
	agenda.addContact(Contact(first_n, last_n, nick_n, phone_num, darkest_secret));
	if (std::cin.eof()==1) {
		return ;
	}
	first_n.clear();
	last_n.clear();
	nick_n.clear();
	phone_num.clear();
	darkest_secret.clear();
}

int	main(void)
{
	std::string	action;
	std::string	index;
	PhoneBook	agenda;

	while (1)
	{
		std::cout << "Choose an action: ADD, SEARCH, EXIT: ";
		std::getline(std::cin, action);

		if (action == "ADD")
			add(agenda);
		else if (action == "SEARCH")
		{
			agenda.displayContacts();
			std::cout << "Enter index: ";
			std::getline(std::cin, index);
			agenda.printIndex(index);
		}
		else if (action == "EXIT")
			return (0);
		if (std::cin.eof()==1) {
			std::cout << "\n";
			return (0);
		}
	}
}
