#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->last_contact = 0;
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
