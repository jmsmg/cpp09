#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
#include <stdexcept>
#include <iostream>

class	BitcoinExchange
{
	private:
		std::string					arg;
		std::map<std::string, int>	*_data;

	public:
		BitcoinExchange();
		// BitcoinExchange(const BitcoinExchange &obj);
		// BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj);
		// ~BitcoinExchange();

		std::map<std::string, int> getData();
		std::map<std::string, int> getInput();
};

std::map<std::string, double>	*make_map(std::ifstream	&file, char delemeter);

#endif