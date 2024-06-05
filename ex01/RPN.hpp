#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;

		void	checkInput(char *input);
		void	calculator(char charactor);
		int		basicOperation(int first, int second, char oper);
	
	public:
		RPN();
		RPN(const RPN &rpn);
		RPN	&operator=(const RPN &rpn);
		~RPN();

		void	process(char *input);
};
#endif