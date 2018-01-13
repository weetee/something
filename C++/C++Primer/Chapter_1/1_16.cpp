#include <iostream>

using namespace std;

int main()
{
	cout << "Please input some numbers: ";
	int num, sum = 0;
	while (cin >> num)
	{
		sum += num;
	}
	cout << "the sum of this numbers is: " << sum << endl;
	return 0;
}
