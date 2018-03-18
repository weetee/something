#include <iostream>

using namespace std;

int main()
{
    float a = 1;
    cout << "(int)a = " << (int)a << ", (int &)a = " << (int &)a << endl;
    cout << boolalpha << ((int)a == (int &)a) << endl;
    float b = 0;
    cout << "(int)b = " << (int)b << ", (int &)b = " << (int &)b << endl;
    cout << boolalpha << ((int)b == (int &)b) << endl;
    return 0;
}
