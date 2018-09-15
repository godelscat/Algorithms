#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H
#include <iostream>
#include <memory>
#include <algorithm>

template <class T>
struct node {
    T key;
    int degree;
    std::shared_ptr<node<T>> parent;
    std::shared_ptr<node<T>> child;
    std::shared_ptr<node<T>> sibling;
    node (T k) : key(k) { };
    node ( ) { };
};

template <class T>
using sptr = std::shared_ptr<node<T>>;

template <class T>
class BinomialHeap {
    private:
        sptr<T> head;
    
    public:
        BinomialHeap () {
            head = nullptr;
        }
        void insert (T k);
        T minimum (); 
        void extractMin (); //delete min node
        void decrease (T k1, T k2);
        void remove (T k);
        bool in (T k); //check if key is in heap
        void print ();

    private:
        //chd is the node to be child, and p is to be parent
        void link (sptr<T> chd, sptr<T> p);
        sptr<T> heapUnion (sptr<T> h1, sptr<T> h2); 
        //merge two heap according to degree increasing
        sptr<T> heapMerge (sptr<T> h1, sptr<T> h2);
        sptr<T> treeSearch (sptr<T> root, T k);
        sptr<T> heapSearch (T k);
        void treePrint (sptr<T> root);
};

template <class T>
void BinomialHeap<T>::link (sptr<T> chd, sptr<T> p) {
    chd->parent = p;
    chd->sibling = p->child;
    p->child = chd;
    p->degree += 1;
}

template <class T>
T BinomialHeap<T>::minimum () {
    sptr<T> temp = head;
    T min = head->key;
    while ( temp ) {
        if ( temp->key <= min ) {
            min = temp->key;
        }
        temp = temp->sibling;
    }
    return min;
}

template <class T>
sptr<T> BinomialHeap<T>::heapMerge ( sptr<T> h1, sptr<T> h2 ) {
    sptr<T> nil = std::make_shared<node<T>>();
    sptr<T> temp = nullptr;
    sptr<T> root = nil;
    while ( h1 && h2 ) {
        if ( h1->degree < h2->degree ) {
            temp = h1;
            h1 = h1->sibling;
        } else {
            temp = h2;
            h2 = h2->sibling;
        }
        root->sibling = temp;
        root = root->sibling;
    }
    if ( h1 ) {
        root->sibling = h1;
    } else {
        root->sibling = h2;
    }

    return nil->sibling;
}

template <class T>
sptr<T> BinomialHeap<T>::heapUnion ( sptr<T> h1, sptr<T> h2 ) {
    sptr<T> h = heapMerge ( h1, h2 );
    if ( !h )  return h;
    sptr<T> prev_x (nullptr); //prev node of x
    sptr<T> x = h;
    sptr<T> next_x = x->sibling; //next node of x
    while ( next_x ) {
        //case 1 and case 2
        if ( ( x->degree != next_x->degree ) || ( next_x->sibling && 
            next_x->sibling->degree == x->degree) ) {
                prev_x = x;
                x = next_x;
        } else if ( x->key <= next_x->key ) {
            x->sibling = next_x->sibling;
            link (next_x, x);
        } else {
            if ( !prev_x ) 
                h = next_x;
            else 
                prev_x->sibling = next_x;
            link ( x, next_x );
            x = next_x;
        } 
        next_x = x->sibling;
    }
    return h;
}

template <class T>
void BinomialHeap<T>::insert ( T k ) {
    sptr<T> h = std::make_shared<node<T>>(k);
    head = heapUnion ( head, h );
}

template <class T>
void BinomialHeap<T>::extractMin () {
    sptr<T> h = head;
    sptr<T> x = head; //min root
    sptr<T> prev_x = nullptr; //prev of min root
    if ( !h ) {
        throw std::out_of_range ("Empty Binomial Heap");
    }
    while ( h->sibling ) {
        if ( h->sibling->key < x->key ) {
            prev_x = h;
            x = h->sibling;
        }
        h = h->sibling;
    }
    //remove min binomial tree x from binomial heap
    if ( !prev_x ) {
        head = head->sibling;
    } else {
        prev_x->sibling = x->sibling;
    }

    //reverse the order of the linked list of x's children 
    //setting the parent pointer of each child to nullptr, and build a binomial heap H'
    //set another binomial heap to point to the head of H' 
    sptr<T> temp = nullptr;
    sptr<T> next = nullptr;
    sptr<T> h_prime = nullptr;
    sptr<T> chd = x->child;
    if ( chd ) {
        chd->parent = nullptr;
        while ( chd->sibling ) {
            next = chd->sibling;
            chd->sibling = temp;
            temp = chd;
            chd = next;
            chd->parent = nullptr;
        }
        chd->sibling = temp;
        h_prime = chd;
    }
    head = heapUnion ( head, h_prime );
}

template <class T>
sptr<T> BinomialHeap<T>::treeSearch ( sptr<T> root, T k ) {
    if ( root ) {
	if ( root->key == k )
		return root;
	else {
		treeSearch ( root->child, k );
		root = root->sibling;
	}
    } else {
        return nullptr;
    }
}

template <class T>
sptr<T> BinomialHeap<T>::heapSearch ( T k ) {
    sptr<T> root = head;
    sptr<T> target = nullptr;
    if ( !root ) {
        return nullptr;
    }
    while ( root ) {
        target = treeSearch ( root, k );
        if ( target ) return target;
        root = root->sibling;
    }
    return target;
}

template <class T>
bool BinomialHeap<T>::in (T k) {
    if ( heapSearch(k) ) 
        return true;
    else 
        return false;
}

template <class T>
void BinomialHeap<T>::decrease ( T k1, T k2 ) {
    if ( k2 >= k1 ) {
        throw std::invalid_argument ("Input is larger the orginal value");
    }
    sptr<T> target = heapSearch (k1);
    if ( !target ) {
        throw std::invalid_argument ("Input does not exist");
    }
    sptr<T> y = target;
    sptr<T> z = y->parent;
    while ( z && z->key > y->key ) {
        std::swap ( z->key, y->key );
        y = z;
        z = z->p;
    }
}

template <class T>
void BinomialHeap<T>::remove (T k) {
    T temp = minimum() - 11; //random number to make sure temp is the smallest
    decrease( k, temp );
    extractMin();
}

template <class T>
void BinomialHeap<T>::treePrint ( sptr<T> root ) {
    if ( root ) {
        std::cout << "key is : " << root->key << "\n";
        treePrint ( root->child );
        treePrint ( root->sibling );
    }
}

template <class T>
void BinomialHeap<T>::print () {
    sptr<T> root = head;
    while ( root ) {
        treePrint (root);
        root = root->sibling;
    }
}

#endif
