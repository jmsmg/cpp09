#include <iostream>
#include <vector>
#include <algorithm> // std::find


int		jacobsthal(int n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

int main()
{
	int jacob_idx;

	for (size_t i = 0; i < 7; i++)
	{
		jacob_idx = jacobsthal(i);
		while (jacobsthal(i - 1) < jacob_idx)
		{
			std::cout << jacob_idx << " ";
			jacob_idx--;
		}
	}

    return 0;
}
