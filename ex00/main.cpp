#include "BitcoinExchange.hpp"
#include <stdexcept>

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw (std::invalid_argument("not found argument"));

		std::ifstream	data("data.csv");
		std::ifstream	input(argv[1]);

		if (!data || !input)
			throw (std::runtime_error("unable to open file."));

		std::map<std::string, double> *data_map;

		data_map = makeMap(data, ',');
		BitcoinExchange	bitcoin(&input, data_map);
		bitcoin.print();

		delete data_map;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}