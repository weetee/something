#include "SalesData.h"

using namespace std;

int main()
{
	SalesData total;
	if (Read(cin, total))
	{
		SalesData item;
		while (Read(cin, item))
		{
			if (total.Isbn() == item.Isbn())
			{
				total.Combine(item);
			}
			else
			{
				Print(cout, total) << endl;
				total = item;
			}
		}
        Print(cout, total) << endl;
	}
	else
	{
		cerr << "No data!?" << endl;
	}
}
