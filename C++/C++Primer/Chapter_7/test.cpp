#include <iostream>
#include <string>

using namespace std;

class Test
{
    public:
        Test(int p_num) : m_num(p_num) {}
        void Print() const
        {
            std::cout << m_num << std::endl;
        }

    private:
        int m_num;
};

int main()
{
    const Test t = Test(5);
    t.Print();  //when t is const, it only can call class const function
    return 0;
}
