#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    try
    {
        if (num2 == 0)
            throw runtime_error("Error num");
        cout << num1 / num2 << endl;
    }
    catch (runtime_error err)
    {
        cout << "error:" << err.what() << endl;
    }
    return 0;
}
