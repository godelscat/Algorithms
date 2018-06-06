#include<iostream>
using namespace std;

template <class T>
void MERGE(T *arr, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	T L[n1], R[n2];
	for (int l = 0; l < n1; ++l){
		L[l] = arr[p+l];
	}
	for (int r = 0; r < n2; ++r){
	       R[r] = arr[q+r+1];
	}

	int i = 0;
	int j = 0;
	while (i < n1 && j < n2){
		for (int k = p; k <= r; ++k){
			if (L[i] <= R[j]){
				arr[k] = L[i];
				i = i + 1;
			} else{
				arr[k] = R[j];
				j = j + 1;
			}
		}
	}

	if (i < n1){
		for (int k = p+n2+i; k <= r; ++k){
			arr[k] = L[i];
		}
	} else{
		for (int k = p+n1+j; k <= r; ++k){
			arr[k] = R[j];
		}
	}
}


int main()
{
	int testArr[] = {2,4,5,7,1,2,3,6};
	//p start from 0; r end end by length-1
	MERGE<int>(testArr, 0, 3, 7);
	for (auto c : testArr)
		cout << c << endl;
	return 0;
}

