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
    
    cout << "------------" << endl;
    int (*p_arr)[2] = arr;
    cout << *(*(p_arr+1)+1) << endl; //3

    cout << "------------" << endl;
    char str[][10] = {"China", "Beijing"};
    char *p_str = str[0];
    cout << p_str + 10 << endl;   //Beijing

    return 0;
}

