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
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange(std::string filename, std::string input_file);
		std::map<std::string, double> getDict() const;

		void bitcoinPrices();
		void setSourceFileDict();
		void printValues(std::string date, double value);

	private:
		std::map<std::string, double> _src_dict;
		std::map<std::string, double> _input_dict;
		std::string _src_file;
		std::string _input_file;
};

#endif
