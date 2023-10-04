#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string phone_number;
	std::string darkest_secret;

	public:
	Contact();
	Contact(const std::string first, const std::string last,
			const std::string nick, const std::string phone,
			const std::string secret);

	std::string getFirstName(void);
};

#endif
