#include <iostream>
#include "mylist_v2.h"
using namespace std;

int main ()
{
	doublyList<int> testList;
	testList.ListInsert(1);
	testList.ListInsert(4);
	testList.ListInsert(16);
	testList.ListInsert(9);
	testList.ListShow();
	shared_ptr<node<int>> a = testList.ListSearch(16);
	testList.ListDelete(a);
	cout << "after delete" << endl;
	testList.ListShow();
	return 0;
}

