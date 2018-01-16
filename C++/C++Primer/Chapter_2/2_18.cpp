#include <iostream>

int main()
{
    int num, *p_num = &num;
    num = 10;
    std::cout << *p_num << std::endl;
    *p_num = 15;
    std::cout << num << std::endl;
    int num2 = 5;
    p_num = &num2;
    std::cout << *p_num << '\n' << num << '\n' << num2 << std::endl;
    return 0;
}
