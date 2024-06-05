#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		std::cout << argc << std::endl;
		std::cout << argv[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}