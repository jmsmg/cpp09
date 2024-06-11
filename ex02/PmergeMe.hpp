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

		void	binarySearch(int a, int	b)
		{
			int	left = 0;
			int	right = std::find(this->_array.begin(), this->_array.end(), a);

			while ()
			{

			}
		}

		void	mergeArray(int fair_size)
		{
			T		a;
			T		b;
			int		remain;
			size_t	i = 0;

			remain = this->_n % fair_size;
			while (i + fair_size < this->_n)
			{
				a.push_back(this->_array[i]);
				b.push_back(this->_array[i + (fair_size / 2)]);
				i += fair_size;
			}
			if (remain && fair_size / 2 <= remain) // 딱 떨어지지 않고, B2가 생성되어야 할 때
			{
				b.push_back(this->_array[i]);
			}
			std::cout << "변형 전 a : ";
			for (typename T::iterator a_it = a.begin(); a_it != a.end(); a_it++)
			{
				std::cout << *a_it << " ";
			}
			std::cout << "변형 전 b : ";
			for (typename T::iterator b_it = b.begin(); b_it != b.end(); b_it++)
			{
				std::cout << *b_it << " ";
			}
			std::cout << std::endl;
			std::cout << std::endl;
			// a,b 순서 정하기
			T	tmp;
			int i = 0;
			for (typename T::iterator b_it = b.begin(); b_it != b.end(); b_it++)
			{
				binarySearch(a.begin() + i, *b_it);
				i++;
			}
			// std::cout << "여기 합친거 : ";
			// for (typename T::iterator a_it = a.begin(); a_it != a.end(); a_it++)
			// {
			// 	std::cout << *a_it << " ";
			// }
			std::cout << std::endl;
		}

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
			{
				std::cout << "fair " << fair_size << std::endl;
				this->mergeArray(fair_size);
				return ;
			}

			fordJohnson(depth + 1, fair_size * 2);
			std::cout << "fair " << fair_size << std::endl;
			mergeArray(fair_size);
			// 이후에 각 depth 3, 2, 1로 올라가며 정렬 진행?
			// 값으로 찾기
		};

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