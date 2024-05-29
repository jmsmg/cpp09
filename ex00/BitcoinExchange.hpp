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

		time_t	transUnixTime(std::string str);
		bool	checkDate(std::string buff);
		double	findDate(std::string buff);
		void	printLine(std::string line);
		void	print(void);
};

std::map<std::string, double>	*makeMap(std::ifstream	&file, char delemeter);

#endif