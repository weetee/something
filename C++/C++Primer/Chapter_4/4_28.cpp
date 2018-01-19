#include <iostream>

using namespace std;

int main()
{
    cout << "sizeof int = " << sizeof(int) << endl;
    cout << "sizeof long = " << sizeof(long) << endl;
    cout << "sizeof long long = " << sizeof (long long) << endl;
    cout << "sizeof short = " << sizeof(short) << endl;
    cout << "sizeof char = " << sizeof(char) << endl;
    cout << "sizeof int * = " << sizeof(int*) << endl;

    int x[10];
    int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;

    return 0;
}
