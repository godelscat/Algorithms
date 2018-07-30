//Problem 10.2 in CLRS
//using sorted singly linked list
#ifndef MERGE_HEAP_H
#define MERGE_HEAP_H
#include <iostream>

struct node {
	int key;
	node* next;
};

class Heap {
	public :
		node* head;
		Heap ();
		~Heap ();
		void insert (int x);
		int min ();
		int extractMin ();
		void merge (node* head1, node* head2);
		void show ();
};

Heap::Heap () {
	head = nullptr;
}

Heap::~Heap() {
	node* temp = nullptr;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

void Heap::insert (int x) {
	node* temp = new node;
	temp->key = x;
	if ( head == nullptr || x < head->key ) {
	       	temp->next = head;
       		head = temp;
 	} else {
		node* temp1 = new node;
		temp1 = head;
		while ( temp1->next != nullptr && x > temp1->next->key ) {
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}

int Heap::min () {
	if ( head != nullptr ) return head->key;
}

int Heap::extractMin () {
	if ( head != nullptr ) {
		int x = head->key;
		head = head->next;
		return x;
	}
}

void Heap::merge ( node* head1, node* head2 ) {
	node* temph = new node;
	node* temp = temph->next;
	while ( head1 != nullptr && head2 != nullptr ) {
		if ( head1->key < head2->key ) {
			temp = head1;
			head1 = head1->next;
			temp = temp->next;
		} else {
			temp = head2;
			head2 = head2->next;
			temp = temp->next;
		}

	}
	if ( head1 != nullptr ) temp->next = head1;
	else temp->next = head2;
	head = temph->next;
	delete temph;
}

void Heap::show () {
	node* temp = head;
	while ( temp != nullptr ) {
		std::cout << temp->key << std::endl;
	       temp = temp->next;
	}
}

#endif
