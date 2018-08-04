#include <iostream>
#include "opening-address.h"
using namespace std;

int main ()
{
	opening::node n1(10,7), n2(22,3), n3(31,18), n4(4,23), n5(15,17),
		n6(28,1), n7(17,33), n8(88,77), n9(59,46);
	opening::node narr[9] = {n1, n2, n3, n4, n5, n6, n7, n8, n9};
	opening::hash h(11);
	for ( int i = 0; i < 9; ++i ) 
		h.insert ( narr[i] ) ;
	cout << h.search ( 22 ) << endl;
	cout << h.search ( 17 ) << endl;
	cout << h.search ( 4 ) << endl;
//	cout << h.search ( 11 ) << endl;
	return 0;
}

