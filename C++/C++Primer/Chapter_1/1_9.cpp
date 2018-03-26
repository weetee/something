#include <iostream>

using namespace std;

int main()
{
	int sum = 0, val = 1;
	while (val <= 100)
	{
		sum += val;
		++val;
	}
	cout << "the sum of 1 to 100 is " << sum << endl;
	return 0;
}