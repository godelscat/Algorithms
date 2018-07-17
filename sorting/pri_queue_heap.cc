#include <iostream>
#include <algorithm>
#include "Heap.h" 
using namespace std;

int HEAP_MAX ( int arr[], int len) {
	BUILD_MAX_HEAP (arr, len);
	return arr[0];
}

void HEAP_INCRESE_KEY (int arr[], int i, int key) {
	arr[i] = key;
	int pa = (i-1) >> 1;
	while ( i >= 0 && arr[i] > arr[pa] ) {
		swap (arr[pa], arr[i]);
		i -- ;
		pa = (i-1) >> 1;
	}
}
int HEAP_EXTRACT_MAX (int arr[], int len) {
	BUILD_MAX_HEAP ( arr, len);
	int max = arr[0];
	arr[0] = arr[len-1];
	MAX_HEAPIFY (arr, 0, len-1);
	return max;
}

int main ()
{
	int testArr[] = {2,3,1,5,7,4};
	int len = sizeof(testArr)/sizeof(*testArr);
	int max = HEAP_EXTRACT_MAX (testArr, len);
	cout << "max value is : " << max << endl;
	return 0;
}
