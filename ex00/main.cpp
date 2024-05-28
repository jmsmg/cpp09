#include "BitcoinExchange.hpp"
#include <stdexcept>

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw (std::invalid_argument("not found argument"));

		std::ifstream	data("data.csv");
		std::ifstream	input(argv[1]);

		if (!data || !input)
			throw (std::runtime_error("unable to open file."));

		std::map<std::string, double> *data_map;

		data_map = make_map(data, ',');
		for (std::map<std::string, double>::iterator it = data_map->begin(); it != data_map->end(); it++)
		{
			std::cout << "key : " << it->first << " value : " << it->second << std::endl;
		}
		// input을 앞, 뒤로 쪼갬
		// map의 key를 unix time으로 변환해서 다시 원래대로 돌리는 것 고민해야함
		// 에러처리 -> 2001-42-42
		// 숫자를 탐색함
		// 에러처리 -> input value 음수, overflow
		// value 값 곱함

		delete data_map;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}