#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: pass a valid file as argument" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc(argv[1]);
		btc.bitcoinPrices();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
