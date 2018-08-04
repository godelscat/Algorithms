#ifndef OPENING_ADDRESS_H
#define OPENING_ADDRESS_H
#include <iostream>
#include <memory>

namespace opening
{
	struct node {
		int key;
		int val;
		node (int k, int v) : key(k), val(v) {} ;
	};

	class hash {
		private :
			int max;
			std::unique_ptr<node* []> arr = std::make_unique<node* []>(max);
			int h1 ( int k );
			int h2 ( int k );
			int h ( int k, int i );

		public :
			hash ( int m ) : max(m) {};
			int search ( int k );
			void insert ( node &n );
	};

	int hash::h1 ( int k ) {
		int x = k % max;
		return x ;
	}

	int hash::h2 ( int k ) {
		int x = k % ( max -1 ) + 1 ; 
		return x ;
	}

	int hash::h ( int k ,int i ) {
		int x = ( h1(k) + i * h2(k) ) % max;
		return x;
	}

	void hash::insert ( node &n ) {
		int i;
		for ( i = 0; i < max; ++i ) {
			int temp = h ( n.key, i );
			if ( arr[temp] == nullptr ) {
				//why can use normal ptr 
				//why cannot use make_unique initialize
				arr[temp] = &n;
				break;
			}
		}
		if ( i == max ) throw std::out_of_range ("Hash Table is FULL");
	}

	int hash::search ( int k ) {
		for ( int i = 0; i < max; ++i ) {
			int temp = h ( k, i );
			if ( arr[temp] != nullptr && arr[temp]->key == k )
				return arr[temp]->val;
		}
		throw std::invalid_argument ("Key NOT exist");
	}
}

#endif
