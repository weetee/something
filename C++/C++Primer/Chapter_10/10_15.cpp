#include <iostream>

using namespace std;

int main()
{
    int val1,val2;
    cin >> val1 >> val2;
    auto func = [val1](const int val) { return val + val1; };
    cout << "sum is : " << func(val2) << endl;
    return 0;
}
