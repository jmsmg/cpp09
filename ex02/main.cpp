#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		// std::cout << argc << std::endl;
		// std::cout << argv[1] << std::endl;
		std::vector<int> array;

		PmergeMe<std::vector<int> > a;

		a.inputArguments(argc, argv);
		a.fordJohnson(1, 2);
		// for (std::vector<int>::iterator it = a.getArray().begin(); it != a.getArray().end(); it++)
		// {
		// 	std::cout << *it << std::endl;
		// }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}