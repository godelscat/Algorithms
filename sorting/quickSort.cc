#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
int Partition (T arr[], int p, int r) {
	T pivot_elem = arr[r];
	int j = p - 1;
	for (int i = p; i < r; i++) {
		if (arr[i] <= pivot_elem) {
			j ++;
			swap (arr[i], arr[j]);
		}
	}
	swap (arr[j+1], arr[r]);
	return j+1;
}

template <class T>
void QuickSort (T arr[], int p , int r) {
	if (p < r) {
		int q = Partition<T> (arr, p, r);
		QuickSort (arr, p, q-1);
		QuickSort (arr, q+1, r);
	}
}

int main ()
{
	int testArr[] = {2,3,1,4,7,5,0};
	int len = sizeof(testArr)/sizeof(*testArr);
	QuickSort<int> (testArr, 0, len-1);
	for (auto c : testArr) cout << c << endl;
	return 0;
}
