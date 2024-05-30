#include "RPN.hpp"

RPN::RPN() : _stack()
{
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN	&RPN::operator=(const RPN &rpn)
{
	if (this != &rpn)
	{
		this->_stack = rpn._stack;
	}
	return (*this);
}

RPN::~RPN()
{

}

void	RPN::process(char *input)
{
	this->checkInput(input);
	for (int i = 0; input[i]; i++)
	{
		this->calculator(input[i]);
	}
}

void	RPN::calculator(char charactor)
{
	int	first;
	int	second;

	if (this->_stack.size() <= 2 && !isdigit(charactor))
	{
		throw std::invalid_argument("Error: Invalid Reverse Polish Notation format.");
	}
	first = this->_stack.top();
	this->_stack.pop();
	second = this->_stack.top();
	this->_stack.pop();

	// 연산자 구해야함
}
void	RPN::checkInput(char *input)
{
	for (int i = 0; input[i]; i++)
	{
		if (i % 2 == 0)
		{
			if (!isdigit(input[i]) || input[i] != '+' || input[i] != '-' || input[i] != '*' || input[i] != '/')
			{
				throw (std::invalid_argument("Error : Expected a operator."));
			}
		}
		else if (i % 2 == 1 && input[i] != ' ')
		{
			throw (std::invalid_argument("Error : Expected a space character."));
		}
	}
	// 스택에 넣어햐함
}