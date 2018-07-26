#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>

template <class T>
struct node {
	T x;
	node *next;
};

template <class T>
class myStack {
	private :
		node<T> *top;
	public :
		myStack();
		~myStack();
		bool isEmpty();
		T pop();
		void push(T elem);
};

template <class T>
myStack<T>::myStack () {
	top = nullptr;
}

//free all node memory
template <class T>
myStack<T>::~myStack () {
	node<T> *temp = nullptr;
	while (top != nullptr) {
		temp = top;
		top = top->next;
		delete temp;
		}
}

template <class T>
bool myStack<T>::isEmpty () {
	return top == nullptr;
}

template <class T>
void myStack<T>::push (T elem) {
	node<T> *temp = new node<T>;
	temp->x = elem;
	temp->next = top;
	top = temp;
}

template <class T>
T myStack<T>::pop () {
	if (top != nullptr) {
		node<T> *temp = top;
		top = top->next;
		return temp->x;
	}
}

#endif
