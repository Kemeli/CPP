#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void	printContacts(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << "|";
}

int	cpp_atoi(std::string str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
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
		std::cout << "Enter index: ";
		std::getline(std::cin, index);
		if (!index.empty())
		{
			i = cpp_atoi(index);
			if (i < 0 || i > 7 || this->contacts_list[i].getFirstName().empty()){
				std::cout << "Invalid index" << std::endl;
				index.clear();
			}
		}
	}
	std::cout << this->contacts_list[i] << std::endl;
}

void PhoneBook::displayContacts()
{
	int i = 0;
	while (i < 8 && !this->contacts_list[i].getFirstName().empty())
	{
		std::cout << "|" << std::setw(10) <<  i << "|";
		printContacts(this->contacts_list[i].getFirstName());
		printContacts(this->contacts_list[i].getLastName());
		printContacts(this->contacts_list[i].getNickname());
		std::cout << "\n";
		i++;
	}
}

void PhoneBook::addContact(const Contact c)
{
	if (this->index == 8)
		this->index = 0;
	std::cout << this->index << std::endl;
	this->contacts_list[this->index] = c;
	this->index++;
}
