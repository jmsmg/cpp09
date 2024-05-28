#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>
#include <cstdlib>

class	BitcoinExchange
{
	private:
		std::string						_arg;
		std::map<std::string, double>	*_data;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string arg, const std::map<std::string, double> *data);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

		std::map<std::string, int> getData();
		std::map<std::string, int> getInput();
};

std::map<std::string, double>	*make_map(std::ifstream	&file, char delemeter);

#endif