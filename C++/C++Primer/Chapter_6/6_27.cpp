#include <iostream>
#include <initializer_list>

using namespace std;

int SumOfSomeNumbers(initializer_list<int> lst_int)
{
    int sum = 0;
    for (const auto &i : lst_int)
        sum += i;
    return sum;
}

int main()
{
    int sum = SumOfSomeNumbers({1,2,3,4,5,6,7,8,9});
    cout << sum << endl;
    return 0;
}
