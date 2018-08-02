#include <iostream>
#include "myqueue.h"
using namespace std;

int main ()
{
	cirQueue<int> testQueue(5);
	cout << "isEmpty : " << testQueue.isEmpty() << endl;
	testQueue.EnQueue(2);
	testQueue.EnQueue(5);
	testQueue.EnQueue(1);
	testQueue.EnQueue(7);
	cout << "isFull : " << testQueue.isFull() << endl;
	cout << testQueue.DeQueue() << endl;
	cout << testQueue.DeQueue() << endl;
	cout << testQueue.DeQueue() << endl;
	cout << testQueue.DeQueue() << endl;
	cout << testQueue.DeQueue() << endl;
	return 0;
}

