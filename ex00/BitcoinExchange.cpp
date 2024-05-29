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

void	BitcoinExchange::printLine(std::string line, int num)
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
		it = this->_data->find(buff);
		if (it != this->_data->end())
		{
			out += buff;
			out += " => ";
			value = it->second;
		}
		// TODO error
	}
	if (std::getline(iss, buff, ' '))
	{
		if (buff != "|")
		{
			std::cerr << "Error: bad input " << line << std::endl;
			return ;
		}
	}
	if (std::getline(iss, buff, ' '))
	{
		if (atof(buff.c_str()) < 0)
		{
			std::cerr << "Error: too large a number." << std::endl;
		}
		if ((2147483647 < atof(buff.c_str())))
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return ;
		}
		out += buff;
		out += " = ";
	}
	std::cout << out << atof(buff.c_str()) * value << std::endl;
}

void	BitcoinExchange::print(void)
{
	int			num = 0;
	std::string	line;

	std::getline(*(this->_input), line);
	if (line != "date | value")
	{
		std::cerr << "line : " << num + 1 << std::endl;
		throw (std::invalid_argument("Error: input file error"));
	}

	while (std::getline(*(this->_input), line))
	{
		this->printLine(line, num);
		num++;
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
