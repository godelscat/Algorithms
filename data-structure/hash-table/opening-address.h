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
	
	template<std::size_t N>
	class hash {
		private :
			int max = N;
			//using std::array insted
			//std::unique_ptr<node* []> arr = std::make_unique<node* []>(max);
			std::array <std::unique_ptr<node>, N> arr;
			int h1 ( int k );
			int h2 ( int k );
			int h ( int k, int i );

		public :
			int search ( int k );
			void insert ( node &n );
	};

	template<std::size_t N>
	int hash<N>::h1 ( int k ) {
		int x = k % max;
		return x ;
	}

	template<std::size_t N>
	int hash<N>::h2 ( int k ) {
		int x = k % ( max -1 ) + 1 ; 
		return x ;
	}

	template<std::size_t N>
	int hash<N>::h ( int k ,int i ) {
		int x = ( h1(k) + i * h2(k) ) % max;
		return x;
	}

	template<std::size_t N>
	void hash<N>::insert ( node &n ) {
		int i;
		for ( i = 0; i < max; ++i ) {
			int temp = h ( n.key, i );
			if ( arr[temp] == nullptr ) {
				//why can use normal ptr 
				//why cannot use make_unique initialize
				//arr[temp] = &n;
				arr[temp] = std::make_unique<node>(n.key, n.val);
				break;
			}
		}
		if ( i == max ) throw std::out_of_range ("Hash Table is FULL");
	}

	template<std::size_t N>
	int hash<N>::search ( int k ) {
		for ( int i = 0; i < max; ++i ) {
			int temp = h ( k, i );
			if ( arr[temp] != nullptr && arr[temp]->key == k )
				return arr[temp]->val;
		}
		throw std::invalid_argument ("Key NOT exist");
	}
}

#endif
