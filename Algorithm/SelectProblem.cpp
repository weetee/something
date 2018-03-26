#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		cout << "need two parameters:\n\t1: data file name;\n\t2: k value" << endl;
		return -1;
	}

	ifstream in_file(argv[1]);
	if (!in_file)
	{
		cout << "can't open file: " << argv[1] << endl;
		return -2;
	}

	int k = atoi(argv[2]);
	if (k < 0)
	{
		cout << "k value can't less than 0~!" << endl;
		return -3;
	}
	vector<int> i_vec;
	int num;
	while (in_file >> num)
	{
		i_vec.push_back(num);
	}
	if (i_vec.size() < k)
	{
		cout << "data count less than k value!" << endl;
		return -4;
	}
	sort(i_vec.begin(), i_vec.end(), [](int a, int b)->bool {return a > b;});
	cout << "the " << k << " max value is: " << i_vec[k-1] << endl;

	return 0;
}
