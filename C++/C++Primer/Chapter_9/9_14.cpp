#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main()
{
    list<const char *> lst_str{"hello", "world", "hi"};
    vector<string> vec_str;
    vec_str.assign(lst_str.cbegin(), lst_str.cend());
    auto beg = vec_str.cbegin();
    while (beg != vec_str.cend())
    {
        cout << *beg++ << endl;
    }

    return 0;
}

