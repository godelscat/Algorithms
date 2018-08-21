#include <iostream>
#include <array>
using namespace std;
const int n = 7; //# of matrix
const int t = n + 1; 
const int MAX = 32767;

void matrix_chain_order ( array<int, t> &p, array<array<int, n>, n> &m, array<array<int, n>, n> &s ) {
	//l is the chain length
	for ( int l = 2; l <= n; ++l ) {
		for ( int i = 0; i <= n - l; ++i ) {
			int j = i + l - 1;
			m[i][j] = MAX;
			for ( int k = i; k < j; ++k ) {
				int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if ( q < m[i][j] ) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void memoized_matrix_chain ( array<int, t> &p, array<array<int, n>, n> &m , array<array<int, n>, n> &s, int i, int j ) {
	if ( m[i][j] != MAX ) return;
	if ( i == j ) {
		m[i][j] = 0;	
		s[i][j] = i;
	} else {
		for ( int k = i; k < j; ++k ) {
			memoized_matrix_chain ( p, m, s, i, k ) ;
			memoized_matrix_chain ( p, m, s, k+1, j ) ;
			int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
			if ( m[i][j] > q ) {
				m[i][j] = q;
				s[i][j] = k;
			}
		}
	}
}

void print_optimal_parens ( array<array<int, n>, n> &s, int i, int j ) {
	if ( i == j ) cout << "A" << i;
	else {
		cout << "(";
		print_optimal_parens ( s, i, s[i][j] );
		print_optimal_parens ( s, s[i][j]+1, j );
		cout << ")";
	}
}

int main () 
{
	array<array<int, n>, n> m = { {0} };
	array<array<int, n>, n> s = { {0} };
	array<int, t> p = {30, 35, 15, 5, 10, 20, 25};
//	matrix_chain_order ( p, m, s );
	for ( auto &row : m ) 
		for ( auto &col : row ) 
			col = MAX;
	memoized_matrix_chain ( p, m, s, 0, 5 );	
	print_optimal_parens ( s, 0, 5 );
	cout << "\n";
	return 0;
}
