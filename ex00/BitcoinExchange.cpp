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
	cur->tm_mon = atof(str.c_str()) - 1;

	std::getline(is, str, '-');
	cur->tm_mday = atof(str.c_str());

	ret = mktime(cur);
	return (ret);
}

double	BitcoinExchange::findDate(std::string buff)
{
	time_t	input = this->transUnixTime(buff);
	time_t	curr = 0;
	double	value = 0;
	std::string	last;
	std::map<std::string, double>::iterator	it = this->_data->begin();

	if (input < this->transUnixTime(this->_data->begin()->first))
	{
		throw (std::runtime_error("Error: bad input => "));
	}
	while (it != this->_data->end())
	{
		curr = this->transUnixTime(it->first);
		if (curr <= input)
			value = it->second;
		if (input < curr)
			return (value);
		it++;
	}
	--it;
	value = it->second;
	return (value);
}

bool	BitcoinExchange::checkDate(std::string buff)
{
	time_t				raw = this->transUnixTime(buff);
	struct tm			*after = localtime(&raw);
	std::istringstream	is(buff);
	std::map<std::string, double>::iterator	it;

	std::getline(is, buff, '-');
	if (after->tm_year != atof(buff.c_str()))
		return (true);
	std::getline(is, buff, '-');
	if (after->tm_mon != atof(buff.c_str()) - 1)
	{
		return (true);
	}
	std::getline(is, buff, '-');
	if (after->tm_mday != atof(buff.c_str()))
		return (true);

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
	try
	{
		if (std::getline(iss, buff, ' '))
		{
			if (checkDate(buff))
				throw (std::runtime_error("Error: bad input => "));
			value = this->findDate(buff);
			out += buff;
			out += " => ";
		}
		else
			throw (std::runtime_error("Error: bad input => "));
		if (std::getline(iss, buff, ' '))
		{
			if (buff != "|")
				throw (std::runtime_error("Error: bad input => "));
		}
		else
			throw (std::runtime_error("Error: bad input => "));
		if (std::getline(iss, buff, ' '))
		{
			if (atof(buff.c_str()) < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				return ;
			}
			if (1000 < atof(buff.c_str()))
			{
				std::cerr << "Error: too large a number." << std::endl;
				return ;
			}
			out += buff;
			out += " = ";
		}
		else
			throw (std::runtime_error("Error: bad input => "));
		std::cout << out << atof(buff.c_str()) * value << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << line << '\n';
	}
	
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

	std::getline(data, line);
	if (line != "date,exchange_rate")
	{
		throw (std::invalid_argument("Error: data file error"));
	}
	while (std::getline(data, line))
	{
		std::istringstream is(line);
		std::getline(is, key, delemeter);
		std::getline(is, value, delemeter);
		(*map)[key] = atof(value.c_str());
	}
	return (map);	
}
