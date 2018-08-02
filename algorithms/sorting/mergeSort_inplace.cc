//in-place version of merge sort
#include <iostream>
#include <algorithm>
using namespace std;

void reverse (int arr[], int begin, int end) {
	int i = begin, j = end;
	while (i < j) {
		swap ( arr[i], arr[j]);
		++i;
		--j;
	}
}

void merge (int arr[], int p, int q, int r) {
	int i = p, j = q + 1;
	while (i < j && j <= r) {
		while ( arr[i] < arr[j] && i < j)  ++i;
		int step = 0;
		while ( arr[j+step] < arr[i] && (j+step) <= r) 
			++step;
		reverse (arr, i, q);
		reverse (arr, j, j+step-1);
		reverse (arr, i, j+step-1);
		i += step;
	}
}

void mergeSort (int arr[], int p, int r) {
	if (p < r) {
		int q = (p + r) >> 1;
		mergeSort (arr, p, q);
		mergeSort (arr, q+1, r);
		merge (arr, p, q, r);
	}
}

int main ()
{
	int testArr[] = {4,2,6,5,11,9,7,12};
	int len = sizeof(testArr)/sizeof(*testArr);
	mergeSort (testArr, 0, len-1);
	for (auto c : testArr) cout << c << endl;
	return 0;
}

