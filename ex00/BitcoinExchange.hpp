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
		std::ifstream					*_input;
		std::map<std::string, double>	*_data;

	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream *input, std::map<std::string, double> *data);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange	&operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

		std::map<std::string, int> getData(void);
		std::map<std::string, int> getInput(void);

		void	printLine(std::string line, int num);
		void	print(void);
		double	transUnixTime(std::string str);
};

std::map<std::string, double>	*makeMap(std::ifstream	&file, char delemeter);

#endif