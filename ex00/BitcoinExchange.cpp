#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _arg(NULL), _data(NULL)
{
}

BitcoinExchange::BitcoinExchange(const std::string arg, const std::map<std::string, double> *data)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		this->_arg = obj._arg;
		this->_data = obj._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}


std::map<std::string, double>	*make_map(std::ifstream	&file, char delemeter)
{
	std::string	line;
	std::string key;
	std::string value;
	std::map<std::string, double>	*map = new std::map<std::string, double>;

	while (std::getline(file, line))
	{
		// std::cout << line << std::endl;
		std::istringstream is(line);
		std::getline(is, key, delemeter);
		std::getline(is, value, delemeter);
		(*map)[key] = atof(value.c_str());
	}
	return (map);	
}