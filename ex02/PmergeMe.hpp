#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <deque>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>

template <typename T>
class PmergeMe
{
	private:
		size_t				_n;
		T					_array;

	public:
		PmergeMe() : _n(0), _array()
		{
		};
		
		PmergeMe(size_t n) : _n(n), _array()
		{
		};
		
		PmergeMe(const PmergeMe &pmergeme)
		{
			*this = pmergeme;
		};
		PmergeMe	&operator=(const PmergeMe &pmergeme)
		{
			if (this != &pmergeme)
			{
				this->_n = pmergeme._n;
				this->_array = pmergeme._array;
			}
			return (*this);
		};
		~PmergeMe()
		{
		};

		void	inputArguments(int argc, char *argv[])
		{
			std::set<int>		tmp;
			std::vector<int>	vec;
			if (argc < 2)
			{
				throw (std::invalid_argument("Error : invalid argument count"));
			}
			for (int i = 1; i < argc; i++)
			{
				for (int j = 0; argv[i][j]; j++)
				{
					if (!std::isdigit(argv[i][j]))
					{
						std::cerr << static_cast<std::string>(argv[i]) << std::endl;
						throw (std::invalid_argument("Error : is not a natural number"));
					}
					else if (INT_MAX < atoll(argv[i]))
					{
						std::cout << argv[i] << std::endl;
						throw (std::runtime_error("Error : argument is not intger"));
					}
				}
				this->_array.push_back(atoi(argv[i]));
				tmp.insert(atoi(argv[i]));
				if (tmp.size() != this->_array.size())
					throw (std::runtime_error("Error : duplicate number"));
			}
			this->_n = this->_array.size();
		};

		void	fordJohnson(int depth, int fair_size)
		{
			if (this->_array.size() == 0 || this->_array.size() == 1) // 에러처리
			{
				throw (std::runtime_error("Error : invalid array size"));
			}

			size_t idx = 0;
			while (fair_size * (idx + 1) < this->_n)
			{
				typename T::iterator a = this->_array.begin() + idx * fair_size;
				typename T::iterator b = a + (fair_size / 2);
				typename T::iterator last = b + (fair_size / 2);
				if (*a < *b)
					std::rotate(a, b, last);
				idx++;
			}

			if (idx == 1) // 탈출
				return ;

			fordJohnson(depth + 1, fair_size * 2);
			// this->mergeArray();
			// 이후에 각 depth 3, 2, 1로 올라가며 정렬 진행?
			// 값으로 찾기
		};
		// void	mergeArray(T &array, int fair_size);
		int		jacobsthal(int n)
		{
			return ((pow(2, n) - pow(-1, n)) / 3);
		};

		size_t				getN()
		{
			return (this->_n);
		};

		T					&getArray()
		{
			return (this->_array);
		};

		void				setN(size_t n);
		void				setArray(T array);
};
#endif