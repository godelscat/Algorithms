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
	cout << "heap contains 30: " << heap.in(30) << endl;
	cout << "Min value is : " << heap.minimum() << endl;
	heap.extractMin();
	cout << "after extract min, elements are : " << endl;
	heap.print();
	heap.insert(7);
	heap.insert(40);
	heap.print();
	heap.remove(40);
	cout << "after remove, elements are: " << endl;
	heap.print();
	return 0;
}
