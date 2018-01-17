#include <iostream>

using namespace std;

constexpr int Size(int p_num)
{
    return p_num;
}

int j = 10;

int main()
{
    constexpr int i = 10;
    constexpr int num = Size(i);
    cout << num << endl;
    constexpr int *p_j = &j;  //top-level const point
    return 0;
}
