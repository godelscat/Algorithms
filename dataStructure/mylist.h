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
		node<T>* head;

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
	head = nullptr;
}

template <class T>
doublyList<T>::~doublyList() {
	node<T>* temp = head;
	node<T>* current = head;
	while (current != nullptr) {
		temp = current->next;
		delete current;
		current = temp;
	}
}

template <class T>
node<T>* doublyList<T>::ListSearch (T k) {
	node<T>* temp = head;
	while ( temp != nullptr && temp->x != k ) {
		temp = temp->next;
	}
	return temp;
}

template <class T>
void doublyList<T>::ListInsert (T  key) {
	node<T>* temp = new node<T>;
	temp->x = key;
	temp->next = head;
	if (head != nullptr) head->prev = temp;
	head = temp;
	temp->prev = nullptr;
}

template <class T>
void doublyList<T>::ListDelete (node<T>* key) {
	if (key->prev != nullptr) key->prev->next = key->next;
	else head = key->next;
	if (key->next != nullptr) key->next->prev = key->prev;
}

template <class T>
void doublyList<T>::ListShow () {
	node<T>* temp = head;
	while (temp != nullptr) {
		std::cout << temp->x << std::endl;
		temp = temp->next;
	}
}

#endif
