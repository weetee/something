#include <iostream>
#include <vector>

using namespace std;

int MaxSubsequenceSum(const vector<int> &ivec)
{
	int max_sum = 0;
	int current = 0;
	for (auto i : ivec)
	{
		cout << "i = " << i << endl;
		if (max_sum == 0)
		{
			if (i <= 0)
			{
				continue;
			}
			else
			{
				max_sum = i;
				current = i;
			}
		}
		else
		{
			current += i;
			if (current > max_sum)
			{
				max_sum = current;
			}
			if (current <= 0)
			{
				current = 0;
			}
		}
	}
	return max_sum;
}

int main()
{
	vector<int> ivec;
	int num;
	cout << "enter some number: ";
	while (cin >> num)
	{
		ivec.push_back(num);
	}

	int max_sum = MaxSubsequenceSum(ivec);
	cout << "the max sum = " << max_sum << endl;

	return 0;
}
