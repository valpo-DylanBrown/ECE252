#include <stdlib.h>
#include <iostream>

using namespace std;

class Link {
	private:
		int data; //payload
		Link * next;  //pointer

	public:
		Link();   //default constructor
		Link(int x){ next = NULL; data = x; };  //non-default constructor

		int getData() {return data;}  //getters
		Link* getNext() {return next;}

		void setData(int x) {data=x;}  //setters
		void setNext(Link * nextLink) {next=nextLink;}
};


int main () {

	Link * first = new Link(1);
	Link * second = new Link(2);
	Link * third = new Link(3);

	first->setNext(second);
	second->setNext(third);


	Link * curr = first;

	cout << curr->getData() << endl;
	curr = curr->getNext();
	cout << curr->getData() << endl;

	//curr points to 2
	// insert a 7
	Link* seven = new Link(7);
	curr->setNext(seven);
	seven->setNext(third);
	curr = seven;

	cout << curr->getData() << endl;


	//go back to front
	curr = first;
	cout << "Print List: " << endl << endl;
	for(int i=0; i<4; i++){
		cout << curr->getData() << endl;
		curr = curr->getNext();
	}

	curr = first;
	cout << curr->getNext()->getNext()->getData() << endl;

	//remove second element

	curr = first;
	//first->setNext(seven); //cheating
	curr->setNext(curr->getNext()->getNext());
	cout << "deletion: " << endl;
	for(int i=0; i<3; i++){
		cout << curr->getData() << endl;
		curr = curr->getNext();
	}

}
