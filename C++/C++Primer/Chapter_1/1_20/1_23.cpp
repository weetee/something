#include <iostream>
#include <string>
#include <map>
#include "Sales_item.h"

using namespace std;

int main()
{
	map<string, int> isbn_map;
	Sales_item book;
	cout << "Please input a book: ";
	while (cin >> book)
	{
		string isbn = book.isbn();
		++isbn_map[isbn];
		cout << "Please input a book: ";
	}
	map<string, int>::const_iterator c_itr = isbn_map.begin();
	while (c_itr != isbn_map.end())
	{
		cout << c_itr->first << " have " << c_itr->second << endl;
		++c_itr;
	}
	return 0;
}
