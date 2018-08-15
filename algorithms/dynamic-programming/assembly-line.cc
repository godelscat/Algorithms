#include <iostream>
using namespace std;
const int n = 6;

void fastest_way ( int a1[], int a2[], int t1[], int t2[], int e[], int x[], int l1[], int l2[] , int &fs, int &ls ) {
	int f1[n] = {0};
	int f2[n] = {0};
	f1[0] = e[0] + a1[0];
	f2[0] = e[1] + a2[0];
	for ( int i = 1; i < n; ++i ) {
		if ( f1[i-1] + a1[i] <= f2[i-1] + t2[i-1] + a1[i] ) {
			f1[i] = f1[i-1] + a1[i];
			l1[i] = 1;
		} else {
			f1[i] = f2[i-1] + t2[i-1] + a1[i];
			l1[i] = 2;
		}
		if ( f2[i-1] + a2[i] <= f1[i-1] + t1[i-1] + a2[i] ) {
			f2[i] = f2[i-1] + a2[i];
			l2[i] = 2;
		} else {
			f2[i] = f1[i-1] + t1[i-1] + a2[i];
			l2[i] = 1;
		}
		if ( f1[n-1] + x[0] <= f2[n-1] + x[1] ) {
			fs = f1[n-1] + x[0];
			ls = 1;
		} else {
			fs = f2[n-1] + x[1];
			ls = 2;
		}
	}
}

void print_station ( int l1[], int l2[], int &ls ) {
	int i = ls;
	int station = n;
	cout << "line " << i << ", station " << station << endl;
	for ( int j = n-1; j > 0 ; --j ) {
		if ( i == 1 ) {
			i = l1[j];
		} else if ( i == 2 ) {
	  		i = l2[j];		
		}
		station = j;
		cout << "line " << i << ", station " << station << endl;
	}
}

int main () 
{
	int e[2] = {2, 4};
	int x[2] = {3, 2};
	int t1[n-1], t2[n-1];
	t1[0] = 2;
	t1[1] = 3;
	t1[2] = 1;
	t1[3] = 3;
	t1[4] = 4;
	t2[0] = 2;
	t2[1] = 1;
	t2[2] = 2;
	t2[3] = 2;
	t2[4] = 1;

	int a1[n], a2[n];
	a1[0] = 7;
	a1[1] = 9;
	a1[2] = 3;
	a1[3] = 4;
	a1[4] = 8;
	a1[5] = 4;
	a2[0] = 8;
	a2[1] = 5;
	a2[2] = 6;
	a2[3] = 4;
	a2[4] = 5;
	a2[5] = 7;

	int fs = 0;
	int ls = 0;
	int l1[n-1] = {0};
	int l2[n-1] = {0};
	fastest_way ( a1, a2, t1, t2, e, x, l1, l2, fs, ls );
	print_station ( l1, l2, ls );
	return 0;
}
