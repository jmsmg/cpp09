#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw (std::invalid_argument("not found argument"));
		std::ifstream	data("data.csv");
		std::ifstream	input(*argv);
		if (!data || !input);
			throw (std::runtime_error("unable to open file."));

		// 한줄씩 맵에 파싱하며 넣어야함
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}