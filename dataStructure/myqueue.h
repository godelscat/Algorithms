#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>

//circular queue by array
//fixed size, but w/o overflow
template <class T>
class cirQueue {
	private :
		int maxSize;
		T  *head;
		T  *tail;
	public :
		T *arr = new T[maxSize];
		cirQueue (int n);
		bool isFull ();
		bool isEmpty ();
		void EnQueue (T elem);
		T DeQueue ();
};

template <class T>
cirQueue<T>::cirQueue (int n) {
	maxSize = n;
	head = arr;
	tail = arr;
}

template <class T>
bool cirQueue<T>::isFull () {
	return head == tail + 1;
}

template <class T>
bool cirQueue<T>::isEmpty () {
	return head == tail;
}

template <class T>
void cirQueue<T>::EnQueue (T elem) {
	if ( head != tail + 1 ) {
		*tail = elem;
		if (tail != arr + maxSize -1) {
		       tail = tail + 1;
		} else {
	 		tail = arr;
		}
	} else {
		throw std::out_of_range ("Queue is FULL!") ;
	}
}

template <class T>
T cirQueue<T>::DeQueue () {
	if ( head != tail ) {
		T temp = *head;
		if ( head == arr + maxSize - 1 ) {
			head = arr;
		} else {
			head = head + 1;
		}
		return temp;
	} else {
		throw std::out_of_range ("Queue is EMPTY!") ;
	}
}

#endif
