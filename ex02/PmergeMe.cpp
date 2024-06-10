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
void	PmergeMe::fordJohnson(T &array, int depth, int node_size)
{
	if (array.size() == 0 || array.size() == 1) // 에러처리
	{
		throw (std::runtime_error("Error : invalid array size"));
	}

	int i = 0;
	while (node_size * (i + 1) < this->_n)
	{
		T::iterator a = T.begin() + i * node_size;
		T::iterator b = a + (node_size / 2);
		T::iterator last = b + (node_size / 2);
		if (*a < *b)
			T.rotate(a, b, last);
		i++;
	}

	if (n < node_size * 4) // 탈출
	{
		// index error?
		T::iterator a = T.begin();
		T::iterator b = a + (node_size / 2);
		T::iterator last = b + (node_size / 2);

		T.rotate(a, b, last);
		return ;
	}

	fordJohnson(T &array, depth + 1, node_size * 2);

	// 이후에 각 depth 3, 2, 1로 올라가며 정렬 진행?
}

int	PmergeMe::jacobsthal(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

size_t	PmergeMe::getN()
{
	return (this->_n);	
}

std::vector<int>	PmergeMe::getVec()
{
	return (this->_vec);
}

std::deque<int>		PmergeMe::getDeq()
{
	return (this->_deq);
}

void	PmergeMe::setN(size_t n)
{
	this->_n = n;
}

void	PmergeMe::setVec(std::vector<int> &vec)
{
	this->_vec = vec;
}

void	PmergeMe::setDeq(std::deque<int> &deq)
{
	this->_deq = deq;
}