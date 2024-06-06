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
class PmergeMe
{
	private:
		size_t				_n;
		std::vector<int>	_vec;
		std::deque<int>		_deq;

	public:
		PmergeMe();
		PmergeMe(size_t n);
		PmergeMe(const PmergeMe &pmergeme);
		PmergeMe	&operator=(const PmergeMe &pmergeme);
		~PmergeMe();

		void	inputArguments(int argc, char *argv[]);
		template <typename T>
		void	fordJohnson(T &array, int a, int b, int square);
		int		PmergeMe::jacobsthal(int n)
};
#endif