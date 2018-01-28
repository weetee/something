#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

int FindAndInsert(forward_list<string> &fwd_lst, const string &find_str, const string &insert_str)
{
	auto cur = fwd_lst.begin();
	while (cur != fwd_lst.end())
	{
		if (*cur == find_str)
		{
			fwd_lst.insert_after(cur, insert_str);
            return 0;
		}
		else
		{
			++cur;
		}
	}
	return -1;
}

int main()
{
	forward_list<string> fwd_lst{"abc", "def", "hi", "ww"};
	int ret = FindAndInsert(fwd_lst, "hi", "hello");
    if (ret == -1)
    {
        cout << "not find the target string~!" << endl;
        return -1;
    }
	auto beg = fwd_lst.begin();
	while (beg != fwd_lst.end())
		cout << *beg++ << " ";
	cout << "\n";
	return 0;
}
