#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <stdlib.h>

class BitcoinExchange
{
	public:
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange(std::string input_file);

		void	bitcoinPrices();

	private:
		std::map<std::string, double>	_data_dict;
		std::string						_data_file;
		std::string						_input_file;

		BitcoinExchange();
		void	_output(std::string date, double numericValue);
		void	_setDataDict();
		bool	_validValue(double value);
		bool	_isDate(std::string date);
		bool	_checkDateFormat(std::string date);

};

#endif
