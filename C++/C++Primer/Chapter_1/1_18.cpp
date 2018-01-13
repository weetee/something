#include <iostream>

using namespace std;

int main()
{
	int cur_val, val;
	if (cin >> val)
	{
		int cnt = 1;
		cur_val = val;
		while (cin >> val)
		{
			if (val == cur_val)
				++cnt;
			else
			{
				cout << cur_val << " occurs " << cnt << " times." << endl;
				cur_val = val;
				cnt = 1;
			}
		}
		cout << cur_val << " occurs " << cnt << " times." << endl;
	}
	return 0;
}
