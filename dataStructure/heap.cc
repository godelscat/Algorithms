#include <iostream>
#include "mergeHeap.h"
using namespace std;

int main ()
{
	Heap testHeap;
	testHeap.insert (3);
	testHeap.insert (5);
	testHeap.insert (4);
	testHeap.insert (1);
	testHeap.insert (7);
	testHeap.show();
	cout << "min value is : " << testHeap.min() << endl;
	int x = testHeap.extractMin();
	cout << "extract value is : " << x << endl;
	testHeap.show();

	Heap testHeap1;
	testHeap1.insert (2);
	testHeap1.insert (9);
	testHeap1.insert (4);
	testHeap1.insert (8);
	testHeap1.insert (3);	
	cout << "head of testHeap1: " << testHeap1.head << endl;	
	testHeap1.show();

	Heap testMerge;
	testMerge.merge( testHeap.head, testHeap1.head);
	cout << "head of testMerge: " << testMerge.head << endl;
	testMerge.show();
	
	return 0;
}


