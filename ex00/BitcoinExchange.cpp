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

time_t	BitcoinExchange::transUnixTime(std::string str)
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

double	BitcoinExchange::findDate(std::string buff)
{
	time_t	input = this->transUnixTime(buff);
	time_t	curr = 0;
	time_t	tmp = 0;
	double	value = 0;

	for (std::map<std::string, double>::iterator it = this->_data->begin(); it != this->_data->end(); it++)
	{
		curr = this->transUnixTime(it->first);
		if (tmp < curr && curr <= input)
		{
			tmp = curr;
			value = it->second;
		}
	}
	return (value);
}

bool	BitcoinExchange::checkDate(std::string buff)
{
	time_t		raw = this->transUnixTime(buff);
	struct tm	*after = localtime(&raw);
	std::istringstream is(buff);

	std::getline(is, buff, '-');
	if (after->tm_year != atof(buff.c_str()))
	{
		return (true);
	}
	std::getline(is, buff, '-');
	if (after->tm_mon != atof(buff.c_str()))
	{
		return (true);
	}
	std::getline(is, buff, '-');
	if (after->tm_mday != atof(buff.c_str()))
	{
		return (true);
	}
	return (false);
}

void	BitcoinExchange::printLine(std::string line)
{
	std::string								buff;
	std::string								out;
	std::string								date;
	double									value;
	std::istringstream						iss(line);
	std::map<std::string, double>::iterator	it;

	out.reserve(35);
	if (std::getline(iss, buff, ' '))
	{
		if (checkDate(buff))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return ;
		}
		value = this->findDate(buff);
		out += buff;
		out += " => ";
	}
	if (std::getline(iss, buff, ' '))
	{
		if (buff != "|")
		{
			std::cout << "Error: bad input " << line << std::endl;
			return ;
		}
	}
	if (std::getline(iss, buff, ' '))
	{
		if (atof(buff.c_str()) < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return ;
		}
		if ((2147483647 < atof(buff.c_str())))
		{
			std::cerr << "Error: too large a number." << std::endl;
			return ;
		}
		out += buff;
		out += " = ";
	}
	std::cout << out << atof(buff.c_str()) * value << std::endl;
}

void	BitcoinExchange::print(void)
{
	std::string	line;

	std::getline(*(this->_input), line);
	if (line != "date | value")
	{
		throw (std::invalid_argument("Error: input file error"));
	}

	while (std::getline(*(this->_input), line))
	{
		this->printLine(line);
	}
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
