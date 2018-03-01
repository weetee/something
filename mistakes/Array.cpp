#include <iostream>

using namespace std;

int main()
{
    cout << "------------" << endl;
    int arr[3][2] = {{0,1}, {2,3}, {4,5}};
    int *p = arr[0];
    cout << p[0] << endl;   //0

    cout << "------------" << endl;
    int b = 2, c = 7, d = 5;
    int a;
    a = ++b, c--, d+3;
    cout << a << endl;  //3

    cout << "------------" << endl;
    char c_arr[3][3] = {{'a','b','c'},{'d','e','f'}, {'g','h','i'}};
    cout << c_arr[1][4] << endl;    //h

    return 0;
}

