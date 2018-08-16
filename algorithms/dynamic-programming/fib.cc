#include <iostream>
#include <ctime>
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

int fib_normal (int n) {
	if ( n <= 2 ) return 1;
	int result;
	result = fib_normal(n-1) + fib_normal(n-2);
	return result;
}

int main () 
{
	const int n = 20;
	int arr[n] = {0};
	clock_t start, end;
	double msec;
	start = clock();
	int result = fib_memoize (n, arr);
	end = clock();
	msec = double ( end - start ) * 1e6 / CLOCKS_PER_SEC;
	cout << "memoize method takes : " << msec << " microsecond.\n";
	start = clock();
	int test = fib_bottom_up(20);
	end = clock();
	msec = double ( end - start ) * 1e6 / CLOCKS_PER_SEC;
	cout << "bottom to up method takes : " << msec << " microsecond.\n";
	start = clock();
	int fib = fib_normal(20);
	end = clock();
	msec = double ( end - start ) * 1e6 / CLOCKS_PER_SEC;
	cout << "normal method takes : " << msec << " microsecond.\n";
	return 0;
}
