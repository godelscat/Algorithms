#include <iostream>
using namespace std;

int fib_memoize (int n, int arr[]) {
	if ( n <= 2 ) return 1;
	arr[0] = arr[1] = 1;
	int result;
	if ( arr[n-1] ) {
		result = arr[n-1];
	} else {
		result  = fib_memoize(n-1, arr) + fib_memoize(n-2, arr);
		arr[n-1] = result;
	}
	return result;
}

int fib_bottom_up (int n) {
	if ( n <= 2 ) return 1;
	int arr[n] = {0};
	int result;
	arr[0] = arr[1] = 1;
	for ( int i = 2; i < n; ++i ) {
		arr[i] = arr[i-1] + arr[i-2];
	}	
	result = arr[n-1];
	return result;
}

int main () 
{
	const int n = 5;
	int arr[n] = {0};
	int result = fib_memoize (n, arr);
	int test = fib_bottom_up(10);
	cout << "fib(5) is : " << test << endl;
	return 0;
}
