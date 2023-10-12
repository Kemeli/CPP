#include "PhoneBook.hpp"

void	add(PhoneBook &agenda)
{
	std::string	first_n;
	std::string	last_n;
	std::string	nick_n;
	std::string	phone_num;
	std::string	dark_secret;

	while (first_n.empty() && !std::cin.eof()){
		std::cout << "Enter first name:" << std::endl;
		std::getline(std::cin, first_n);
	}
	while (last_n.empty() && !std::cin.eof()){
		std::cout << "Enter last name:" << std::endl;
		std::getline(std::cin, last_n);
	}
	while (nick_n.empty() && !std::cin.eof()){
		std::cout << "Enter nickname:" << std::endl;
		std::getline(std::cin, nick_n);
	}
	while (phone_num.empty() && !std::cin.eof()){
		std::cout << "Enter phone_number:" << std::endl;
		std::getline(std::cin, phone_num);
	}
	while (dark_secret.empty() && !std::cin.eof()){
		std::cout << "Enter darkest_secret:" << std::endl;
		std::getline(std::cin, dark_secret);
	}

	agenda.addContact(Contact(first_n, last_n, nick_n, phone_num, dark_secret));

	first_n.clear();
	last_n.clear();
	nick_n.clear();
	phone_num.clear();
	dark_secret.clear();
}
