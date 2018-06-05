#include <iostream>
using namespace std;

template <class T>
void incre_sorting(T *arr, int size){
	int i, j;
	T key;
	if (size < 2) 
		cout << "only one element, no need to sort." << endl;
	else{
		for (j = 1; j < size; ++j){
			key = arr[j];
			i = j - 1;
			while (arr[i] > key && i>=0){
				arr[i+1] = arr[i];
				i = i - 1;
			}
			arr[i+1] = key;
		}
	}
}

template <class T>
void decre_sorting(T *arr, int size){
	int i,j;
	T key;
	if (size < 2 ){
		cout << "only one element, no need to  sort." << endl;
	} else {
		for (j = 1; j < size; ++j){
			key = arr[j];
			i = j - 1;
			while (arr[i] < key && i >= 0){
				arr[i+1] = arr[i];
				i = i - 1;
			}
			arr[i+1] = key;
		}
	}
}

int main()
{
	double testArr1[] = {2.1, 1.2, 4.3, 7.9, 0.1};
	int testArr2[] =  {4, 1, 3, 2, 7, 9};
	int s1 = (sizeof(testArr1)/sizeof(*testArr1));
	int s2 = (sizeof(testArr2)/sizeof(*testArr2));
	incre_sorting<double>(testArr1, s1);
	decre_sorting<int>(testArr2, s2);
	for (auto c : testArr1)
		cout << c << endl;
	for (auto c : testArr2)
		cout << c << endl;
	return 0;
}

