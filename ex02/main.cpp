#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		PmergeMe<std::vector<int> > a;

		a.inputArguments(argc, argv);
		a.fordJohnson(1, 2);
		for (size_t i = 0; i < a.getArray().size(); i++)
		{
			std::cout << a.getArray()[i] << " ";
		}
		std::cout << std::endl;
		std::sort(a.getArray().begin(), a.getArray().end());
		for (size_t i = 0; i < a.getArray().size(); i++)
		{
			std::cout << a.getArray()[i] << " ";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}