#include "SingleList.h"

int main()
{
	SingleList my_slist;
	my_slist.InsertList(1,0);
	my_slist.InsertList(2,0);
	my_slist.InsertList(3,1);
	my_slist.InsertList(4,0);
	my_slist.InsertList(5,2);
	my_slist.InsertList(6,2);
	my_slist.InsertList(6,2);
	my_slist.InsertList(6,2);
	my_slist.PrintList();

	my_slist.ReverseList();
	my_slist.PrintList();

	my_slist.RemoveList(1);
	my_slist.PrintList();

	my_slist.ReverseList();
	my_slist.PrintList();

	return 0;
}
