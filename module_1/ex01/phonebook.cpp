#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void	PhoneBook::search(PhoneBook &agenda)
{
	std::string	index;
	int			i;

	agenda.displayContacts();
	while (index.empty())
	{
		if (std::cin.eof())
			return ;
		std::cout << "Enter index:" << std::endl;
		std::getline(std::cin, index);
		if (!index.empty())
		{
			i = cpp_atoi(index);
			if (i < 0 || i > 7 || this->contacts[i].getFirstName().empty()){
				std::cout << "Invalid index" << std::endl;
				index.clear();
			}
		}
	}
	std::cout << this->contacts[i] << std::endl;
}

void PhoneBook::displayContacts()
{
	int i = 0;
	while (i < 8 && !this->contacts[i].getFirstName().empty())
	{
		std::cout << "|" << std::setw(10) <<  i << "|";
		printContacts(this->contacts[i].getFirstName());
		printContacts(this->contacts[i].getLastName());
		printContacts(this->contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
}

void PhoneBook::addContact(const Contact c)
{
	if (this->index == 8)
		this->index = 0;
	std::cout << this->index << std::endl;
	this->contacts[this->index] = c;
	this->index++;
}
