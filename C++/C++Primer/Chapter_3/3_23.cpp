#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> ivec;
    int num;
    while (cin >> num)
    {
        ivec.push_back(num);
    }
    auto itr_b = ivec.begin();
    auto itr_e = ivec.end();
    while (itr_b != itr_e)
    {
        *itr_b *= 2;
        ++itr_b;
    }
    for (auto i : ivec)
        cout << i << endl;
    return 0;
}
