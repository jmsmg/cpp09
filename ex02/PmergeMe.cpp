#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _n(0), _vec(), _deq()
{

}

PmergeMe::PmergeMe(size_t n) : _n(n), _vec(), _deq()
{
	this->_vec.reserve(n);
	this->_deq.resize(n);
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
	*this = pmergeme;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &pmergeme)
{
	if (this != &pmergeme)
	{
		this->_n = pmergeme._n;
		this->_vec = pmergeme._vec;
		this->_deq = pmergeme._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

void	PmergeMe::inputArguments(int argc, char *argv[])
{
	long long	tmp = 0;

	if (argc < 2)
	{
		throw (std::invalid_argument("Error : invalid argument count"));
	}
	for (size_t i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!std::isdigit(argv[i][j]))
			{
				std::cerr << static_cast<std::string>(argv[i]) << std::endl;
				throw (std::invalid_argument("Error : is not a number"));
			}
			else if (INT_MAX < atoll(argv[i]))
			{
				std::cout << argv[i] << std::endl;
				throw (std::runtime_error("Error : argument is not intger"));
			}
		}
		this->_deq.push_back(atoi(argv[i]));
		this->_vec.push_back(atoi(argv[i]));
	}
}

template <typename T>
T	PmergeMe::fordJohnson(T structure, int a, int b, int depth)
{
	// if ()
	// {

	// }

	// https://80000coding.oopy.io/fc425e08-0c24-4c43-9422-bfae68d55cbf#fc425e08-0c24-4c43-9422-bfae68d55cbf
	// indexing? depth?
}