#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> fwd_int = {1,2,3,4,5,6,7,7,8,9,10,0,11};
	auto prev = fwd_int.before_begin();
	auto curr = fwd_int.begin();
	while (curr != fwd_int.end())
	{
		if (*curr % 2 != 0)
		{
			curr = fwd_int.erase_after(perv);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}

	auto beg = fwd_int.cbegin();
	while (beg != fwd_int.cend())
		cout << *beg++ << " ";
	cout << endl;
	return 0;
}