#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>	_stack;

		void	process(char *input);
		void	checkInput(char *input);
		void	calculator(char charactor);
		
	public:
		RPN(/* args */);
		RPN(const RPN &rpn);
		RPN	&operator=(const RPN &rpn);
		~RPN();

};
