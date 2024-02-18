#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: pass a valid file as argument" << std::endl;
		return (1);
	}

	BitcoinExchange btc(argv[1]);
	btc.bitcoinPrices();
}
