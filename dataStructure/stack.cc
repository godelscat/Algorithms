#include <iostream>
#include "mystack_v2.h"
using namespace std;

int main () 
{
	myStack<int> testStack;
	testStack.push(2);
	testStack.push(4);
	testStack.push(7);
	cout << "is testStack empty: " << testStack.isEmpty() << endl;
	while (!testStack.isEmpty()) {
		cout << testStack.pop() << endl;
	}
	return 0;
}	
