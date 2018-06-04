#include <iostream>
using namespace std;

template <class T>
void insert_sorting(T *arr, int size){
	int i, j;
	T key;
	if (size < 2) 
		cout << "only one element, no need to sort." << endl;
	else{
		for (j = 1; j < size; ++j){
			key = arr[j];
			i = j - 1;
			while (arr[i] > key){
				arr[i+1] = arr[i];
				i = i - 1;
			}
			arr[i+1] = key;
		}
	}
}

int main()
{
	double testArr[] = {2.1, 1.2, 4.3, 7.9, 0.1};
	int s = (sizeof(testArr)/sizeof(*testArr));
	insert_sorting<double>(testArr, s);
	for (auto c : testArr)
		cout << c << endl;
	return 0;
}

