//using smart pointer 
#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <memory>

template <class T>
struct node {
	T x;
	std::shared_ptr<node<T>> next;
	node (T data) : x(data) {};
};

template <class T>
class myStack {
	private :
		std::shared_ptr<node<T>> top;
	public :
		myStack();
		bool isEmpty();
		T pop();
		void push(T elem);
};

template <class T>
myStack<T>::myStack () {
	top = nullptr;
}

template <class T>
bool myStack<T>::isEmpty () {
	return top == nullptr;
}

template <class T>
void myStack<T>::push (T elem) {
	//or comment node constructor 
	//just initialied with make_shared<node<T>>();
	std::shared_ptr<node<T>> temp = std::make_shared<node<T>>(elem);
	temp->next = top;
	top = temp;
}

template <class T>
T myStack<T>::pop () {
	if (top != nullptr) {
		std::shared_ptr<node<T>> temp = top;
		top = top->next;
		return temp->x;
	}
}

#endif
