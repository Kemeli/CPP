#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->last_contact = 0;
}

void	getContacts(std::string str)
{
	while (str.length() < 9)
		str = " " + str;
	std::cout << str << "|";
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

void	PhoneBook::printIndex(std::string index)
{
	int	i;

	i = cpp_atoi(index);
	if (i > this->last_contact)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << this->contacts_list[i] << std::endl;
}

void PhoneBook::displayContacts()
{
	int i = 0; //index precisa ser 1 talvez
	while (i <= this->last_contact)
	{
		std::cout << "|         " << i << "|";
		getContacts(this->contacts_list[i].getFirstName());
		getContacts(this->contacts_list[i].getLastName());
		getContacts(this->contacts_list[i].getNickname());
		std::cout << "\n";
		i++;
	}
}

void PhoneBook::addContact(const Contact c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (this->contacts_list[i].getFirstName() == "") //se a posição atual estiver vazia
		{
			this->contacts_list[i] = c;
			this->last_contact = i;
			break ;
		}
		i++;
	}
	if (i == 8)
	{
		i = this->last_contact + 1;
		this->contacts_list[i] = c;
		this->last_contact = i;
	}
}
