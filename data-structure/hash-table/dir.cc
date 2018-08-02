#include <iostream>
#include "direct-address.h"
using namespace std;

int main ()
{
	node n1(2,4), n2(3,7), n3(6,5), n4(8,10);
	myhash::hash h;
	h.insert ( n1 );
	h.insert ( n2 );
	h.insert ( n3 );
	h.insert ( n4 );
	int k = h.search (6);
	cout << k << endl;
	return 0;
}

