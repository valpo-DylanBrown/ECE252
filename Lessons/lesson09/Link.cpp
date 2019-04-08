#include <stdlib.h>
#include <iostream>

using namespace std;

class Link {
	private:
		int data; //payload
		Link * next;  //pointer

	public:
		Link() {data = -1; next = NULL;}   //default constructor
		Link(int x) {data = x; next = NULL;}  //non-default constructor

		int getData() {return data;}  //getters
		Link* getNext() {return next;}

		void setData(int x) {data=x;}  //setters
		void setNext(Link * nextLink) {next=nextLink;}
};


int main () {

	Link * first = new Link(7);
	Link * second = new Link(3);
	Link * third = new Link(8);

	first->setNext(second);
	second->setNext(third);

}
