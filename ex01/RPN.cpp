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

int	RPN::basicOperation(int first, int second, char oper)
{
	long long	result;

	result = 0;
	if (oper == '+')
	{
		result = first + second;
	}
	else if (oper == '-')
	{
		result = first - second;
	}
	else if (oper == '/')
	{
		if (second == 0)
		{
			throw (std::invalid_argument("Error: Division by zero."));
		}
		result = first / second;
	}
	else if (oper == '*')
	{
		result = first * second;
	}

	if (result < -2147483648 || 2147483647 < result)
		throw (std::invalid_argument("Error: Overflow."));
	return (result);
}

void	RPN::calculator(char charactor)
{
	int	first;
	int	second;

	if (this->_stack.size() < 2 && !isdigit(charactor))
	{
		throw std::invalid_argument("Error: Invalid Reverse Polish Notation format.");
	}
	if (isdigit(charactor))
	{
		this->_stack.push(charactor - '0');
	}
	else
	{
		second = this->_stack.top();
		this->_stack.pop();
		first = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(this->basicOperation(first, second, charactor));
	}
}

void	RPN::checkInput(char *input)
{
	for (int i = 0; input[i]; i++)
	{
		if (i % 2 == 0)
		{
			if (!std::isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/')
			{
				throw (std::invalid_argument("Error : Expected a operator."));
			}
		}
		else if (i % 2 == 1 && input[i] != ' ')
		{
			throw (std::invalid_argument("Error : Expected a space character."));
		}
	}
}

void	RPN::process(char *input)
{
	this->checkInput(input);
	for (int i = 0; input[i]; i++)
	{
		if (i % 2 == 0)
			this->calculator(input[i]);
	}
	if (this->_stack.size() != 1)
		throw (std::invalid_argument("Error: Invalid Reverse Polish Notation format."));
	std::cout << this->_stack.top() << std::endl;
}