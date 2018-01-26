#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Need read file : " << endl;
        return -1;
    }
    ifstream in(argv[1]);
    vector<string> str_vec;
    if (in)
    {
        //string line;
        //while (getline(in, line)) 
            //str_vec.push_back(line);
        string word;
        while (in >> word)
            str_vec.push_back(word);
    }
    auto beg_itr = str_vec.cbegin();
    while (beg_itr != str_vec.cend())
        cout << *beg_itr++ << endl;
    return 0;
}
