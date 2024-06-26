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
#include <sys/time.h>
#include <ctime>

template <typename T>
class PmergeMe
{
	private:
		size_t							_n;
		T								_array;
		std::vector<int>				_remain;
		std::vector<T>					_a;
		std::vector<T>					_b;

	public:
		PmergeMe() : _n(0), _array()
		{
		}

		PmergeMe(size_t n) : _n(n), _array()
		{
		}

		PmergeMe(const PmergeMe &pmergeme)
		{
			*this = pmergeme;
		}

		PmergeMe	&operator=(const PmergeMe &pmergeme)
		{
			if (this != &pmergeme)
			{
				this->_n = pmergeme._n;
				this->_array = pmergeme._array;
			}
			return (*this);
		}

		~PmergeMe()
		{
			
		}

		void	rebuildSortedArray(std::vector<T> &tmp)
		{
			this->_array.clear();
			for (size_t i = 0; i < tmp.size(); i++)
			{
				for (size_t j = 0; j < tmp[i].size(); j++)
				{
					this->_array.push_back(tmp[i][j]);
				}
			}
			for (size_t i = 0; i < this->_remain.size(); i++)
			{
				this->_array.push_back(this->_remain[i]);
			}
			this->_a.clear();
			this->_b.clear();
			this->_remain.clear();
		}

		T	&makeJacobsthalArray(T &jacob_array)
		{
			for (size_t i = 2; jacobsthal(i) <= this->_a.size(); i++)
			{
				jacob_array.push_back(jacobsthal(i));
			}
			return (jacob_array);
		}

		size_t	jacobsthal(int n)
		{
			return ((pow(2, n) - pow(-1, n)) / 3);
		}

		void	binarySearch(int idxa, std::vector<T> &tmp, int idxb)
		{
			int						left = 0;
			int						mid = 0;
			int						right = 0;
			typename std::vector<T>::iterator	it;

			it = std::find(tmp.begin(), tmp.end(), this->_a[idxa]);

			right = std::distance(tmp.begin(), it);
			while (left <= right)
			{
				mid = left + ((right - left) / 2);
				if (tmp[mid][0] < this->_b[idxb][0])
				{
					left = mid + 1;
				}
				else if (this->_b[idxb][0] < tmp[mid][0])
				{
					right = mid - 1;
				}
			}
			if (this->_b[idxb][0] < tmp[mid][0])
			{
				tmp.insert(tmp.begin() + mid, this->_b[idxb]);
			}
			else if (this->_b[idxb][0] > tmp[mid][0])
			{
				tmp.insert(tmp.begin() + mid + 1, this->_b[idxb]);
			}
		}

		void	findArrayIdx(std::vector<T> &tmp)
		{
			size_t	i = 1;
			T		jacob_array;

			jacob_array = makeJacobsthalArray(jacob_array);
			while (i < jacob_array.size())
			{
				int	j = 0;
				while (jacob_array[i - 1] < jacob_array[i] - j)
				{
					binarySearch(jacob_array[i] - j - 1, tmp, jacob_array[i] - j - 1);
					j++;
				}
				i++;
			}
			int j = 0;
			while (jacob_array[i - 1] < static_cast<int>(this->_b.size()) - j)
			{
				binarySearch(this->_a.size() - 1, tmp, this->_b.size() - j - 1);
				j++;
			}
		}

		void	mergeArray(void)
		{
			std::vector<T>	tmp;

			tmp.push_back(this->_b[0]);
			for (size_t i = 0; i < this->_a.size(); i++)
			{
				tmp.push_back(this->_a[i]);
			}
			findArrayIdx(tmp);
			rebuildSortedArray(tmp);
		}

		void	makeArray(size_t fair_size)
		{
			size_t		r_size;
			size_t		j;
			size_t		i = 0;

			r_size = this->_n % fair_size;
			while (i + fair_size <= this->_n)
			{
				j = 0;
				T	tmp;
				while (j < fair_size / 2)
				{
					tmp.push_back(this->_array[i + j]);
					j++;
				}
				this->_a.push_back(tmp);
				j = 0;
				T	tmpb;
				while (j < fair_size / 2)
				{
					tmpb.push_back(this->_array[i + j + (fair_size / 2)]);
					j++;
				}
				this->_b.push_back(tmpb);
				i += fair_size;
			}
			if (r_size)
			{
				T	tmp;
				j = 0;
				while (fair_size / 2 <= r_size && j < fair_size / 2) 
				{
					tmp.push_back(this->_array[i + j]);
					j++;
				}
				if (j)
					this->_b.push_back(tmp);
				while (i + j < this->_n)
				{
					this->_remain.push_back(this->_array[i + j]);
					j++;
				}
			}
		}

		void	fordJohnson(int depth, size_t fair_size)
		{
			if (this->_array.size() == 0 || this->_array.size() == 1) 
			{
				throw (std::runtime_error("Error : invalid array size"));
			}

			size_t idx = 0;
			while (fair_size * (idx + 1) <= this->_n)
			{
				typename T::iterator a = this->_array.begin() + idx * fair_size;
				typename T::iterator b = a + (fair_size / 2);
				typename T::iterator last = b + (fair_size / 2);
				if (*a < *b)
					std::rotate(a, b, last);
				idx++;
			}
			if (this->_n / 2 < fair_size) 
			{
				this->makeArray(fair_size);
				mergeArray();
				return ;
			}

			fordJohnson(depth + 1, fair_size * 2);
			makeArray(fair_size);
			mergeArray();
		}

		void	inputArguments(int argc, char *argv[])
		{
			std::set<int>		tmp;

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
						throw (std::runtime_error("Error : argument is not intger"));
					}
				}
				this->_array.push_back(atoi(argv[i]));
				tmp.insert(atoi(argv[i]));
				if (tmp.size() != this->_array.size())
					throw (std::runtime_error("Error : duplicate number"));
			}
			this->_n = this->_array.size();
		}

		size_t				getN()
		{
			return (this->_n);
		}
		T					&getArray()
		{
			return (this->_array);
		}
};
#endif