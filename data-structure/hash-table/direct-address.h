#ifndef DIRECT_ADDRESS_H
#define DIRECT_ADDRESS_H
#include <iostream>
#include <memory>
#define MAX 10

struct node {
	int key;
	int val;
	node ( int k, int v ) : key(k), val(v) {};
};

namespace myhash 
{
	class hash {
		private :
			//it's safe to use make_unique
			std::unique_ptr<node* []> arr = std::make_unique<node *[]> (MAX);
		public :
			int search ( int k );
			void insert ( node &n );
			void del ( node &n );
	};

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
