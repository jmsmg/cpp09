#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{

}

std::map<std::string, double>	*make_map(std::ifstream	&file, char delemeter)
{
	std::string	line;
	std::string key;
	std::string value;
	std::map<std::string, double>	*map = new std::map<std::string, std::string>;

	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
		std::istringstream is(line);
		std::getline(is, key, delemeter);
		std::getline(is, value, delemeter);
		(*map)[key] = atof(value.c_str());
	}
	return (map);	
}