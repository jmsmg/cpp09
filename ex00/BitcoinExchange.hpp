#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <map>

class	BitcoinExchange
{
	private:
		std::string					arg;
		std::map<std::string, int>	_data;
		std::map<std::string, int>	_input;

	public:
		// BitcoinExchange();
		// BitcoinExchange(const BitcoinExchange &obj);
		// BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj);
		// ~BitcoinExchange();

		std::map<std::string, int> getData();
		std::map<std::string, int> getInput();
};
#endif