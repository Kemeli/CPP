#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange copy constructor" << std::endl;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange operator=" << std::endl;
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string src_file, std::string input_file)
{
	_src_file = src_file;
	_input_file = input_file;
}

void BitcoinExchange::setSourceFileDict()
{
	std::ifstream	data;
	std::string		line;
	std::string		key;

	data.open(_src_file.c_str(), std::ifstream::in);
	if (data.is_open())
	{
		while(std::getline(data, line))
		{
			size_t		comma = line.find(',');
			std::string	key = line.substr(0, comma);
			std::string	value = line.substr(comma + 1, line.size() - comma);
			_src_dict[key] = std::strtod(value.c_str(), NULL);
		}
		data.close();
	}
}


void BitcoinExchange::bitcoinPrices()
{
	std::ifstream input;
	std::string line;

	setSourceFileDict();

	std::map<std::string, double>::iterator it;
	it = _src_dict.begin();

	input.open(_input_file.c_str(), std::ifstream::in);
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			size_t pipe = line.find(" | ");
			std::string date = line.substr(0, pipe);
			std::string value = line.substr(pipe + 3, line.size() - pipe);
			double numericValue = std::strtod(value.c_str(), NULL);
			std::map<std::string, double>::iterator it = _src_dict.lower_bound(date);
			if (it == _src_dict.begin() || it->first == date)
				std::cout << date << " => " << numericValue << " = " << it->second * numericValue << std::endl;
			else
			{
				--it;
				std::cout << date << " => " << numericValue << " = " << it->second * numericValue << std::endl;
			}


			// std::cout << date << " => " << numericValue << " = " <<  _src_dict[date] << std::endl;
		}
		input.close();
	}
}

// void BitcoinExchange::bitcoinPrices()
// {
// 	setSourceFileDict();
// 	setInputFileDict();

// 	std::map<std::string, double>::iterator it;
// 	for (it = _input_dict.begin(); it != _input_dict.end(); it++)
// 	{
// 		std::cout << it->first << " => " << it->second << " = " << it->second * _src_dict[it->first] << std::endl;
// 	}
// }
