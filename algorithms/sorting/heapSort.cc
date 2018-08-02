//heap sort algorithm
//time cost is O(nlgn)
#include <iostream>
#include <algorithm>
#include "Heap.h"
using namespace std;

void MAX_HEAPIFY (int arr[], int i, int len) { 
	int largest = i;
	int ldex = (i<<1) + 1;
	int rdex = (i<<1) + 2;
	if ( ldex < len && arr[ldex] > arr[i] )  
		largest = ldex;
	if ( rdex < len && arr[rdex] > arr[largest] )
	       	largest = rdex;
	if ( largest != i ) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		MAX_HEAPIFY ( arr, largest, len );
	}
}

void BUILD_MAX_HEAP (int arr[], int len) {
	int soleIndex = len >> 1;
	for ( int i = soleIndex - 1; i >= 0; --i) {
		MAX_HEAPIFY ( arr, i, len);
	}
}

void HEAP_SORT (int arr[], int len) {
	BUILD_MAX_HEAP(arr, len);
	for (int i = len-1; i > 0 ; --i) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		MAX_HEAPIFY ( arr, 0, i );
	}
}

/*
int main ()
{
	int testArr[] = {4,2,5,3,7,1};
	int len = sizeof(testArr)/sizeof(*testArr);
	HEAP_SORT (testArr, len);
	for (auto c : testArr) cout << c << endl;
	return 0;
}
*/
