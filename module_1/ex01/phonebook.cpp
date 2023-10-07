#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->index = -1;
}

void	PhoneBook::search(PhoneBook &agenda)
{
	std::string	index;
	int			i;

	if (agenda.index == -1)
	{
		std::cout << "You should add a contact first!" << std::endl;
		return ;
	}
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
				std::cout << "Invalid index!" << std::endl;
				index.clear();
			}
		}
	}
	std::cout << this->contacts[i];
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
	if (this->index == 8 || this->index == -1)
		this->index = 0;
	this->contacts[this->index] = c;
	this->index++;
}
