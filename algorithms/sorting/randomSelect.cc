#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

template <class T>
int randomPartition ( T arr[], int p, int r ) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(p, r);
	int x = dis(gen);
	swap (arr[x], arr[r]);
	T pivot = arr[r];
	int j = p;
	for (int i = p; i < r; ++i) {
		if (arr[i] < pivot) {
			swap (arr[j], arr[i]);
			++j;
		}
	}
	swap (arr[j], arr[r]);
	return j;
}

template <class T>
T randomSelect ( T arr[], int p, int r, int i) {
	if (p == r) return arr[p];
	int q = randomPartition ( arr, p , r);
	int k = q - p + 1; 
	if ( k == i ) return arr[q];
	else if ( i < k ) return randomSelect ( arr, p, q-1, i);
	else return  randomSelect ( arr, q+1, r, i-k);
}

int main ()
{
	int testArr[] = {2,4,1,5,7,3,11};
	int len = sizeof(testArr)/sizeof(*testArr);
	int sele = randomSelect<int> (testArr, 0, len-1, 5);
	cout << "the fifth value is : " << sele << endl;
	return 0;
}
