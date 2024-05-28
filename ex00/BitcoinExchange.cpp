#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _input(NULL), _data(NULL)
{
}

BitcoinExchange::BitcoinExchange(std::ifstream *input, std::map<std::string, double> *data)
{
	this->_input = input;
	this->_data = data;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		this->_input = obj._input;
		this->_data = obj._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::printLine(std::string line)
{
	std::string			buff;
	std::istringstream	iss(line);

	while (std::getline(iss, buff, ' '))
	{
		// checkDate();
		// checkPipe();
		// chechNumber();
	}
}

void	BitcoinExchange::print(void)
{
	std::string	line;
	std::string	date;
	std::string	value;

	while (std::getline(*(this->_input), line))
	{
		std::string			buf;
		std::istringstream	iss(line);

		while (std::getline(iss, buf, ' '))
		{
			std::cout << buf << std::endl;
		}
	}
}

double	BitcoinExchange::transUnixTime(std::string str)
{
	time_t		ret = 0;
	struct tm	*cur;
	std::istringstream is(str);

	cur = localtime(&ret);

	std::getline(is, str, '-');
	cur->tm_year = atof(str.c_str());

	std::getline(is, str, '-');
	cur->tm_mon = atof(str.c_str());

	std::getline(is, str, '-');
	cur->tm_mday = atof(str.c_str());

	ret = mktime(cur);
	return (ret);
}

std::map<std::string, double>	*makeMap(std::ifstream	&data, char delemeter)
{
	std::string	line;
	std::string key;
	std::string value;
	std::map<std::string, double>	*map = new std::map<std::string, double>;

	while (std::getline(data, line))
	{
		std::istringstream is(line);
		std::getline(is, key, delemeter);
		std::getline(is, value, delemeter);
		(*map)[key] = atof(value.c_str());
	}
	return (map);	
}
