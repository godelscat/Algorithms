#include <iostream>
#include "chaining.h"
using namespace std;

int main ()
{
	cout << "hello world" << endl;
	chaining::node n1(5,3), n2(28,4), n3(19,6), n4(15,1), n5(20,7),
		n6(33,8), n7(12,9), n8(10,24);
	chaining::hash h(9);
	h.ins (&n1);	
	h.ins (&n2);	
	h.ins (&n3);	
	h.ins (&n4);	
	h.ins (&n5);	
	h.ins (&n6);	
	h.ins (&n7);	
	h.ins (&n8);	
	int value = h.s (12);
	cout << "key 12 corresponds to : " << value << endl;
	h.d (15);
	return 0;
}
