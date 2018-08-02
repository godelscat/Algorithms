//time cost is O(n^2)
#include<iostream>
using namespace std;

template<class T>
void bubble_sort(T *arr, int size) {
	for (int i = 0; i < size ; ++i) {
		for (int j = size - 1; j > i; --j) {
			if ( arr[j] < arr[j-1] ) {
				T temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

int main ()
{
	int testArr[5] = {4,3,5,1,7};
	bubble_sort<int>(testArr, 5);
	for (auto c : testArr) cout << c << endl;
	return 0;
}
