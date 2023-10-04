#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(const std::string first, const std::string last,
				const std::string nick, const std::string phone,
				const std::string secret)
{
	this->first_name = first;
	this->last_name = last;
	this->nickname = nick;
	this->login = login;
	this->phone_number = phone;
	this->darkest_secret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (this->first_name);
}

// std::string	Contact::getLastName(void)
// {
// 	return (this->last_name);
// }

// std::string	Contact::getNickname(void)
// {
// 	return (this->nickname);
// }

// std::string	Contact::getPhoneNumber(void)
// {
// 	return (this->phone_number);
// }

// std::string Contact::getDarkestSecret(void)
// {
// 	return (this->darkest_secret);
// }
