#include <iostream>
#include "Sales_item.h"

using namespace std;

int main()
{
	Sales_item book;
	cout << "Please input a book:";
	if (cin >> book)
	{
		Sales_item sum(book);
		Sales_item item(book);
		cout << "enter the same isbn book:";
		while (cin >> book)
		{
			cout << "enter the same isbn book:";
			if (book.isbn() != item.isbn())
			{
				cout << "books' isbn not same!" << endl;
				continue;
			}
			else
			{
				sum += book;
			}
		}
		cout << "the sum of this books is : " << sum << endl;
	}

	return 0;
}
