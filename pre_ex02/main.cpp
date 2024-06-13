#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		std::vector<int> array;

		std::cout << argv[1] << std::endl;
		PmergeMe<std::vector<int> > a;

		std::cout << "hi";
		a.inputArguments(argc, argv);
		std::cout << "hi";
		a.fordJohnson(1, 2);
		// for (size_t i = 0; i < a.getArray().size(); i++)
		// {
		// 	std::cout << a.getArray()[i] << " ";
		// }
		// std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}