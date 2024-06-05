#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cerr << "invalid argument" << std::endl;
		return (1);
	}
	try
	{
		rpn.process(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}