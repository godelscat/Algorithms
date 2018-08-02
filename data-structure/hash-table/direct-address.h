#ifndef DIRECT_ADDRESS_H
#define DIRECT_ADDRESS_H
#include <iostream>

struct node {
	int key;
	int val;
	node ( int k, int v ) : key(k), val(v) {};
};

namespace myhash 
{
	class hash {
		private :
			const int MAX = 10;	
			node **arr = new node*[MAX];
		public :
			hash ();
			~hash ();
			int search ( int k );
			void insert ( node &n );
			void del ( node &n );
	};

	hash::hash(){
		arr[MAX] = {};
	}

	hash::~hash() {
		delete [] arr;
	}

	int hash::search ( int k ) {
		if ( arr[k] == nullptr ) throw std::invalid_argument ("NO SUCH KEY!");
		else {
			int x = arr[k]->val;
			return x;
		}
	}

	void hash::insert ( node &n ) {
		arr[n.key] = &n;
	}

	void hash::del ( node &n ) {
		arr[n.key] = nullptr;
	}
}

#endif
