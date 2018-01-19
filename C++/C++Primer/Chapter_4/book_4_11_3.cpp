#include <iostream>

using namespace std;

int main()
{
	double d_val = 3.14;
	int i_val = static_cast<int>(d_val);
	cout << i_val << " " << d_val << endl;

	const int *p_i = &i_val;
	cout << *p_i << endl;
	int *p_i2 = const_cast<int*>(p_i);
	*p_i2 = 5;
	cout << i_val << " " << *p_i << endl;

	return 0;
}