#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <memory>

template <class T>
struct node {
	T x;
	std::shared_ptr<node<T>> next;
	std::shared_ptr<node<T>> prev;
	node ( int k ) : x(k) {};
};

template <class T>
class doublyList {
	private :
		std::shared_ptr<node<T>> head;

	public :
		std::shared_ptr<node<T>> ListSearch (T k);
		void ListInsert (T  key);
		void ListDelete (std::shared_ptr<node<T>> key);
		void ListShow ();
};

template <class T>
std::shared_ptr<node<T>> doublyList<T>::ListSearch (T k) {
	std::shared_ptr<node<T>> temp = head;
	while ( temp != nullptr && temp->x != k ) {
		temp = temp->next;
	}
	return temp;
}

template <class T>
void doublyList<T>::ListInsert (T  key) {
	std::shared_ptr<node<T>> temp = std::make_shared<node<T>>(key);
	temp->next = head;
	if (head != nullptr) head->prev = temp;
	head = temp;
	temp->prev = nullptr;
}

template <class T>
void doublyList<T>::ListDelete (std::shared_ptr<node<T>> key) {
	if (key->prev != nullptr) key->prev->next = key->next;
	else head = key->next;
	if (key->next != nullptr) key->next->prev = key->prev;
}

template <class T>
void doublyList<T>::ListShow () {
	std::shared_ptr<node<T>> temp = head;
	while (temp != nullptr) {
		std::cout << temp->x << std::endl;
		temp = temp->next;
	}
}

#endif
