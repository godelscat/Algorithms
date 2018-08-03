//one question remain: error when use array of unique_ptr which points to list
#ifndef CHAINING_H
#define CHAINING_H
#include <iostream>
#include <memory>

namespace chaining
{
	struct node {
		int key;
		int val;
		std::shared_ptr<node> next;
		node ( int k, int v) : key(k), val(v)  {};	
	};

	class list {
		private :
			std::shared_ptr<node> head;
		public :
			void insert ( node &n );
			int search ( int k ) ;
			void del ( int k );
	};

	void list::insert ( node &n ) {
		std::shared_ptr<node> temp  = std::make_shared<node>( n.key, n.val ); 
		temp->next = head;
		head = temp;
	}

	int list::search ( int k ) {
		std::shared_ptr<node> temp (head);
		if ( temp != nullptr ) {
			while ( temp->key != k )  temp = temp->next;
			return temp->val;
		} else {
			throw std::invalid_argument ( "No such key");
		}
	}

	void list::del ( int k ) {
		std::shared_ptr<node> temp = head;
		while ( temp->next != nullptr && temp->next->key != k ) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}

	class hash {
		private :
			int max;
			std::unique_ptr<list []> arr = std::make_unique<list []> (max);
		public :
			hash ( int m ) : max(m) {} ;
			int h ( int k );
			void ins ( node &n );
			int s ( int k );
			void d ( int k );
	};

	int hash::h ( int k )  {
		return k % 9;
	}

	void hash::ins ( node &n ) {
		int index = h ( n.key );
		arr[index].insert ( n );
	}
	
	int hash::s ( int k ) {
		int index = h ( k ) ;
		int x = arr[index].search ( k );	
		return x ;
	}

	void hash::d ( int k ) {
		int index = h ( k ) ;
		arr[index].del ( k );
	}	
}
			
#endif
