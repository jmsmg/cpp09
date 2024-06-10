#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <deque>
#include <utility>
#include <cmath>

template <typename T>
class PmergeMe
{
	private:
		size_t				_n;
		T					_array;

	public:
		PmergeMe();
		PmergeMe(size_t n);
		PmergeMe(const PmergeMe &pmergeme);
		PmergeMe	&operator=(const PmergeMe &pmergeme);
		~PmergeMe();

		void	inputArguments(int argc, char *argv[]);
		void	fordJohnson(T &array, int depth, int fair_size);
		void	mergeArray(T &array, int fair_size);
		int		jacobsthal(int n);

		size_t				getN();
		T					&getArray();

		void				setN(size_t n);
		void				setArray(T array);
};
#endif