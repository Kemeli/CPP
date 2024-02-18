#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <stdlib.h>

#define MAX_INT 2147483647

class BitcoinExchange
{
	public:
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange(std::string input_file);

		void bitcoinPrices();

	private:
		BitcoinExchange();
		void _output(std::string date, double numericValue);
		void _setDataDict();
		std::map<std::string, double> _data_dict;
		std::string _data_file;
		std::string _input_file;
};

#endif
