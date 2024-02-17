#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Number of arguments should be two." << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc("data.csv", argv[1]);
		btc.bitcoinPrices();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
}
