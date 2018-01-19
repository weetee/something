#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
	auto cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
	{
		ivec[ix] = cnt;
	}
	auto itr_b = ivec.cbegin();
	while (itr_b != ivec.cend())
		cout << *itr_b++ << " ";
	cout << endl;
	return 0;
}