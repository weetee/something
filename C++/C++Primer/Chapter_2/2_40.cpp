#include <iostream>
#include "SalesData.h"

using namespace std;

int main()
{
	SalesData item;
	while (Input(item))
	{
        item.Output();
	}
    return 0;
}

