#include <stdlib.h>
#include <iostream>

using namespace std;
int main(void)
{
	LLQueue *myLLQ = new LLQueue();

	if (myLLQ -> isEmpty()) cout << "Queue is empty." << endl;
	else cout << "Queue is not empty." << endl;

	myLLQ -> enqueue(5);
	myLLQ -> enqueue(7);
	myLLQ -> enqueue(9);
	myLLQ -> enqueue(11);

	cout <<"There are " << myLLQ -> getSize();
	cout << " elements in the queue." << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;

	myLLQ -> enqueue(15);
	myLLQ -> enqueue(5);
	myLLQ -> enqueue(35);

	cout << "The newest value in the queue is ";
	cout << myLLQ -> getFirst() << "." << endl;

	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;

	cout <<"There are " << myLLQ -> getSize();
	cout << " elements in the queue." << endl;

	for (int i=0; i<10000; i++){ myLLQ->enqueue(i);}

	cout <<"There are " << myLLQ -> getSize();
	cout << " elements in the queue." << endl;

	for (int i=0; i<10000; i++){myLLQ->dequeue();}

	cout <<"There are " << myLLQ -> getSize();
	cout << " elements in the queue." << endl;

	myLLQ -> enqueue(15);
	myLLQ -> enqueue(5);
	myLLQ -> enqueue(35);

	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;

	cout <<"There are " << myLLQ -> getSize();
	cout << " elements in the queue." << endl;

	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;
	cout << "DQ: " << myLLQ -> dequeue() << endl;

	return 0;
}
