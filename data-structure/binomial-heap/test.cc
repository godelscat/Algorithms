#include <iostream>
#include "BinomialHeap.h"
using namespace std;

int main ()
{
	BinomialHeap<int> heap;
	heap.insert(10);
	heap.insert(20);
	heap.insert(30);
	heap.print();
//	cout << "heap contains 20: " << heap.in(20) << endl;
	return 0;
}
