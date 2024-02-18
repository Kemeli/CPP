#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_data_dict = other._data_dict;
	_data_file = other._data_file;
	_input_file = other._input_file;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	_data_dict = other._data_dict;
	_data_file = other._data_file;
	_input_file = other._input_file;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string input_file)
{
	_data_file = "data.csv";
	_input_file = input_file;
}

void BitcoinExchange::_setDataDict()
{
	std::ifstream	data;
	std::string		line;
	std::string		key;

	data.open(_data_file.c_str(), std::ifstream::in);
	if (data.is_open())
	{
		while(std::getline(data, line))
		{
			size_t		comma = line.find(',');
			std::string	key = line.substr(0, comma);
			std::string	value = line.substr(comma + 1, line.size() - comma);
			_data_dict[key] = std::strtod(value.c_str(), NULL);
		}
		data.close();
	}
	else
	{
		std::cout << "Error: could not open data file." << std::endl;
		exit(1);
	}
}

bool BitcoinExchange::_checkDateFormat(std::string date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	return true;
}

bool BitcoinExchange::_isDate(std::string date)
{
	int year = std::strtod(date.substr(0, 4).c_str(), NULL);
	int month = std::strtod(date.substr(5, 2).c_str(), NULL);
	int day = std::strtod(date.substr(8, 2).c_str(), NULL);

	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

void BitcoinExchange::_output(std::string date, double numericValue)
{
	std::map<std::string, double>::iterator it = _data_dict.lower_bound(date);

	if (it == _data_dict.begin() || it->first == date)
		std::cout << date << " => " << numericValue << " = " << it->second * numericValue << std::endl;
	else
	{
		--it;
		std::cout << date << " => " << numericValue << " = " << it->second * numericValue << std::endl;
	}
}

bool BitcoinExchange::_validValue(double value)
{
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::bitcoinPrices()
{
	std::ifstream input;
	std::string line;

	_setDataDict();

	std::map<std::string, double>::iterator it;
	it = _data_dict.begin();

	input.open(_input_file.c_str(), std::ifstream::in);
	if (input.is_open())
	{
		std::getline(input, line);
		while (std::getline(input, line))
		{
			size_t pipe = line.find(" | ");
			std::string date = line.substr(0, pipe);
			std::string value = line.substr(pipe + 3, line.size() - pipe);
			double numericValue = std::strtod(value.c_str(), NULL);

			if (!_checkDateFormat(date) || !_isDate(date))
				std::cout << "Error: bad input => " << date << std::endl;
			else if (_validValue(numericValue))
				_output(date, numericValue);
		}
		input.close();
	}
	else
	{
		std::cout << "Error: could not open input file." << std::endl;
		exit(1);
	}
}
