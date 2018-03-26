#include <iostream>
#include <string>
#include <deque>
#include <list>

using namespace std;

int main()
{
    string word;
    deque<string> deq_str;
    while (cin >> word)
    {
        deq_str.push_back(word);
    }
    
    auto beg = deq_str.cbegin();
    while (beg != deq_str.cend())
        cout << *beg++ << endl;

    return 0;
}

