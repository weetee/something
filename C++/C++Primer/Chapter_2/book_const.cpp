#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    const int &r_i = i; //all const reference is low-level
    const int &r_num = 0;
    //int &r_num2 = 0;    //error

    const int *p_i = &i;    //low-level const
    int const *p_i2 = &i;   //low-level const same as forward
    int *const p_i3 = &i;   //top-level const
    const int *const p_i4 = &i;
    
    cout << "i = " << i << endl;
    *p_i3 = 10;
    cout << "i = " << i << endl;

    return 0;
}

