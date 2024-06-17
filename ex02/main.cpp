#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		PmergeMe<std::vector<int> > a;

		a.inputArguments(argc, argv);

		std::cout << "Before :   ";
		for (size_t i = 0; i < a.getArray().size(); i++)
		{
			std::cout << a.getArray()[i] << " ";
		}
		std::cout << std::endl;

		clock_t vec_time = clock();
		a.fordJohnson(1, 2);
		vec_time = clock() - vec_time;

		std::cout << "After :   ";
		for (size_t i = 0; i < a.getArray().size(); i++)
		{
			std::cout << a.getArray()[i] << " ";
		}
		std::cout << std::endl;

		PmergeMe<std::deque<int> > b;

		b.inputArguments(argc, argv);
		clock_t deq_time = clock();
		b.fordJohnson(1, 2);
		deq_time = clock() - deq_time;
		std::cout << "After :   ";
		for (size_t i = 0; i < a.getArray().size(); i++)
		{
			std::cout << a.getArray()[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " element with std::vector : " << static_cast<float>(vec_time) * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " element with std::dequeue : " << static_cast<float>(deq_time) * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}