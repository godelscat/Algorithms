#include <iostream>
#include <algorithm>
using namespace std;


int max (int arr[], int len) {
	int l = arr[0];
	for (int i = 0; i < len; ++i){
		if (arr[i] > l) 
			l = arr[i];
	}
	return l;
}

void countSort (int A[], int B[], int k, int len) {
	int temp[k+1] = {};
	for (int i = 0; i < len; ++i) 
		++temp[A[i]];
	for (int i = 1; i <= k; ++i) 
		temp[i] = temp[i] + temp[i-1];
	//in order to be stable, from end to start;
	for (int i = len - 1; i >= 0; --i) {
		B[temp[A[i]]] = A[i];
		--temp[A[i]];
	}
}

int main () 
{
	int testArr[] = {4,3,5,1,6,2,2,7};
	int len = sizeof(testArr)/sizeof(*testArr);
	int k = max (testArr, len);
	int storedArr[len] = {};
	countSort (testArr,storedArr, k, len);
	for (auto c : storedArr) cout << c << endl;
	return 0;
}
