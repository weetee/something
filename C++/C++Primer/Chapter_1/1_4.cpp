#include <iostream>

int main()
{
	std::cout << "Please input two numbers:";
	int val1, val2;
	std::cin >> val1 >> val2;
	std::cout << "the product of " << val1 << " and " << val2
	<< " = " << val1 * val2 << std::endl;
	return 0;
}
