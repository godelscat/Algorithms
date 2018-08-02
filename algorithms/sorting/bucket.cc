#include <iostream>
using namespace std;

struct node {
	int key;
	node* next;
};

class list {
	public :
		list ();
		~list ();
		node* head;
		void insert (int x);
		void merge (node* heads[], int num);
		void store (int arr[]);
		void show ();
};

list::list () {
	head = nullptr;
}

list::~list() {
	delete head;
}

void list::insert (int x) {
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

//need to change when heads[0] = nullptr
void list::merge (node* heads[], int num) {
	node nil;
	node* temp = &nil;
	for ( int i = 0; i < num; ++i) {
			temp->next = heads[i]; 
	       	while ( temp->next != nullptr ) {
				   temp = temp->next;
			}
	}
	head = nil.next;
}


void list::store (int arr[]) {
	node* temp = head;
	int i = 0;
	while ( temp != nullptr ) {
		//cout << "sizeof temp : " << sizeof(temp->key) << endl;
		arr[i] = temp->key;
		//cout << "size of arr : " << sizeof(arr[i]) << endl;
 		temp = temp->next;
		++i;
	} 
}

void list::show () {
	node* temp = head;
	while ( temp != nullptr ) {
		cout << temp->key << endl;
		temp = temp->next;
	}
}

//assume 5 buckets in range [0,50)
void Bucket (int arr[], int len) {
	list l, l0, l1, l2, l3, l4;
	for (int i = 0; i < len; ++i) {
		int n = arr[i] / 10;
		switch (n) {
			case 0:
				l0.insert ( arr[i] );
				break;
			case 1:
				l1.insert ( arr[i] );
				break;
			case 2:
				l2.insert ( arr[i] );
				break;
			case 3:
				l3.insert ( arr[i] );
				break;
			case 4:
				l4.insert ( arr[i] );
				break;
		}
	}
	node* heads[5] = {l0.head, l1.head, l2.head, l3.head, l4.head};
	l.merge ( heads, 5 );	
	//l.show ();
	l.store(arr);
}

int main ()
{
	int arr[10] = {4, 11, 23, 7, 32, 41, 27, 39, 16, 29};
	Bucket ( arr, 10 );
	for (auto c : arr) cout << c << endl;
	return 0;
}
