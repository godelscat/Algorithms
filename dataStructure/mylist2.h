//this is a doubly linked list with sentinel
#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>

template <class T>
struct node {
	T x;
	node* next;
	node* prev;
};

template <class T>
class doublyList {
	private :
		node<T>* nil ;

	public :
		doublyList();
		~doublyList();
		node<T>* ListSearch (T k);
		void ListInsert (T  key);
		void ListDelete (node<T>* key);
		void ListShow ();
};

template <class T>
doublyList<T>::doublyList() {
	//error: nil = nullptr
	nil = new node<T>;
	nil->next = nil;
	nil->prev = nil;
}

template <class T>
doublyList<T>::~doublyList() {
	node<T>* temp = nil;
	node<T>* current = nil;
	while (current->next != nil) {
		temp = current->next;
		delete current;
		current = temp;
	}
}

template <class T>
node<T>* doublyList<T>::ListSearch (T k) {
	node<T>* temp = nil->next;
	while ( temp != nullptr && temp->x != k ) {
		temp = temp->next;
	}
	return temp;
}

template <class T>
void doublyList<T>::ListInsert (T  key) {
	node<T>* temp = new node<T>;
	temp->x = key;
	temp->next = nil->next;
	nil->next->prev = temp;
	nil->next = temp;
	temp->prev = nil;
}

template <class T>
void doublyList<T>::ListDelete (node<T>* key) {
	key->prev->next = key->next;
	key->next->prev = key->prev;
}

template <class T>
void doublyList<T>::ListShow () {
	node<T>* temp = nil->next;
	while (temp != nil) {
		std::cout << temp->x << std::endl;
		temp = temp->next;
	}
}

#endif
