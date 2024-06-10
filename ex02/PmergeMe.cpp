#include "PmergeMe.hpp"

template<typename T>
PmergeMe<T>::PmergeMe() : _n(0), _array()
{

}

template<typename T>
PmergeMe<T>::PmergeMe(size_t n) : _n(n)
{
}

template<typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &pmergeme)
{
	*this = pmergeme;
}

template<typename T>
PmergeMe<T>	&PmergeMe<T>::operator=(const PmergeMe<T> &pmergeme)
{
	if (this != &pmergeme)
	{
		this->_n = pmergeme._n;
		this->_array = pmergeme._array;
	}
	return (*this);
}

template<typename T>
PmergeMe<T>::~PmergeMe()
{

}

template<typename T>
void	PmergeMe<T>::inputArguments(int argc, char *argv[])
{
	long long			tmp = 0;
	std::vector<int>	vec;

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
		this->_array.push_back(atoi(argv[i]));
		vec.sort();
		for (vector<int>::iterator it = vec.begin() + 1; it != vec.end(); it++)
		{
			if (*it == *(it - 1))
				throw (std::runtime_error("Error : duplicate number"));
		}
	}
}

template <typename T>
void	PmergeMe<T>::fordJohnson(T &array, int depth, int fair_size)
{
	if (array.size() == 0 || array.size() == 1) // 에러처리
	{
		throw (std::runtime_error("Error : invalid array size"));
	}

	int idx = 0;
	while (fair_size * (idx + 1) < this->_n)
	{
		T::iterator a = T.begin() + idx * fair_size;
		T::iterator b = a + (fair_size / 2);
		T::iterator last = b + (fair_size / 2);
		if (*a < *b)
			T.rotate(a, b, last);
		idx++;
	}

	if (idx == 1) // 탈출
	{
		this->_array = array;
		return ;
	}

	fordJohnson(T &array, depth + 1, fair_size * 2);
	this->mergeArray();
	// 이후에 각 depth 3, 2, 1로 올라가며 정렬 진행?
	// 값으로 찾기
}

template <typename T>
void	PmergeMe<T>::mergeArray(T &array, int fair_size)
{
	T<int>	a;
	T<int>	b;
	T<int>	tmp;

	int	cnt = this->_n / fair_size;
	int	remain = this->_n % fair_size;
	int	i = 0;

	while (i < cnt)
	{
		a.push_back(T[(i * fair_size)]);
		b.push_back(T[(i * fair_size) + (fair_size / 2)]);
		i++;
	}

	if (remain)
	{
		if (fair_size / 2 < remain)
		{
			b.push_back(T[i * fair_size]);
			tmp.push_back(T[(i * fair_size) + (fair_size / 2)])
		}
		else
			tmp.push_back(T[i * fair_size]);
	}

	// tmp에 삽입 후 합치기
	T::iterator it;

	for ( = array.find(a[1]); ; it++)
	{

	}
	this->_array = array.find(b[1]);
	while (a.empty() && b.empty() && tmp.empty())
	{

	}
	this->_array = push_back();
	array = this->_array;
}

template <typename T>
int	PmergeMe<T>::jacobsthal(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

// template <typename T>
// size_t	PmergeMe<T>::getN()
// {
// 	return (this->_n);	
// }

// template <typename T>
// T	&PmergeMe<T>::getArray()
// {
// 	return (this->_array);	
// }

// template <typename T>
// void	PmergeMe<T>::setN(size_t n)
// {
// 	this->_n = n;
// }

// template <typename T>
// void	PmergeMe<T>::setArray(T &array)
// {
// 	this->_array = T;
// }
