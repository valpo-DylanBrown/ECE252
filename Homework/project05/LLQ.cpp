#include <stdlib.h>
#include <iostream>

using namespace std;

class DLink { //Dylan Brown

	private:
		int data;
		DLink* next;
		DLink* prev;
	public:
		DLink() { next = NULL; data = 0; prev = NULL;}
		DLink (int x) { next = NULL; data = x; prev = NULL;}

		int getData() { return data; }
		DLink* getNext() { return next; }
		DLink* getPrev(){ return prev; }

		void setData (int x) { data = x; }
		void setNext (DLink* nextLink) { next = nextLink; }
		void setPrev (DLink* prevLink) { prev = prevLink; }

};

class LLQueue{ //Dylan Brown
private:
	DLink *front;
	DLink *rear;
	int size;
public:
	LLQueue();
	bool enqueue(int j);
	int dequeue();

	int getSize();
	int getFirst();

	bool isEmpty();

};
LLQueue::LLQueue(){
	front = NULL;
	rear = NULL;
	size = 0;
};
bool LLQueue::enqueue(int j){
	DLink* tmp = new DLink();
	tmp->setData(j);
	tmp->setNext(NULL);
	if(front == NULL){
		front = rear = tmp;
		rear->setNext(NULL);
		size++;

	}
	else{
		rear->setNext(tmp);
		rear = tmp;
		rear->setNext(NULL);
		size++;
	}
	return true;
};
int LLQueue::dequeue(){
	DLink* tmp = new DLink();
	int val;
	if(front == NULL){
		//cout << "empty queue" << endl;
		return -1;
	}
	tmp = front;
	val = tmp->getData();
	front = front->getNext();
	delete(tmp);
	size--;
	return val;

};
int LLQueue::getSize(){
	return size;
};
int LLQueue::getFirst(){
	if(size == 0){
		return -1;
	}
	return front->getData();
}
bool LLQueue::isEmpty(){
	return size == 0;
};

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

//OUTPUT
/*
4c-32-75-9c-9c-29:project05 dylan$ ./a.out
Queue is empty.
There are 4 elements in the queue.
DQ: 5
The newest value in the queue is 7.
DQ: 7
DQ: 9
DQ: 11
DQ: 15
DQ: 5
There are 1 elements in the queue.
There are 10001 elements in the queue.
There are 1 elements in the queue.
DQ: 9999
DQ: 15
DQ: 5
DQ: 35
There are 0 elements in the queue.
DQ: -1
DQ: -1
DQ: -1
*/
