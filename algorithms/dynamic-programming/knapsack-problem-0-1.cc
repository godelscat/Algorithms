//Given a set of items, each with a weight and a value, determine the number 
//of each item to include in a collection so that the total weight is less 
//than or equal to a given limit and the total value is as large as possible.
#include <iostream>
using namespace std;

const int s = 3;
const int weight = 50;

int knapsack_0_1 ( int ks[s+1][weight+1], int val[], int wt[], int n, int w ) {
	if ( ks[n][w] != -1 ) return ks[n][w];
	if ( !n || !w ) {
		ks[n][w] = 0;
		return 0;
	}
	int temp = 0;
	if ( wt[n-1] > w ) temp = knapsack_0_1 ( ks, val, wt, n-1, w ) ;
	else {
		temp = knapsack_0_1 (ks, val, wt, n-1, w) > knapsack_0_1(ks, val, wt, n-1, w-wt[n-1]) +
			val[n-1] ? knapsack_0_1 (ks, val, wt, n-1, w) : knapsack_0_1(ks, val, wt, n-1, w-wt[n-1]) 
			+ val[n-1];
	}
	ks[n][w] = temp;
	return temp;
}

int main ()
{
	int ks[s+1][weight+1] = { {0} };
	for ( auto &row : ks ) 
		for ( auto &col : row)
			col = -1;	
	int val[s] = {60, 100, 120};
	int wt[weight] = {10, 20, 30};
	int p = knapsack_0_1 ( ks, val, wt, 3, 50 );
	cout << "Total value is : " << p << "\n";
	return 0;
}
