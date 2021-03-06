//divide and conquer algorithm for sorting 
//a test for, how the recursive process worked
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

template<class T>
void MERGE_SORT(T *arr, int p, int r){
	if ( p < r ) {
		int q = (p+r)/2;
		//divide
		//conquer recursively
		cout << "start to MERGE-SORT first array\n";
		cout << "p value is : " << p 
			<< "; q value is : " << q << endl;
		MERGE_SORT(arr, p, q);
		cout << "start to MERGE-SORT another array\n";
		cout << "q+1 value is : " << q + 1
			<< "; r value is : " << r << endl;
		MERGE_SORT(arr, q+1, r);
		//combine 
		cout << "starting to merge two arrays" << endl;
		MERGE(arr, p, q, r);
		cout << "p vaule is : " << p << 
			"; q value is : " << q <<
			"; r value is : " << r << endl;
	} else {
		cout << "divide to the smallest piece\n";
	}
}

int main()
{
	int testArr[] = {4,5,7,1,2,3};
	MERGE_SORT<int>(testArr, 0, 5);
	for (auto c : testArr)
		cout << c << endl;
	return 0;
}

