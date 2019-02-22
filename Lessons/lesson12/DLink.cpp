#include <stdlib.h>
#include <iostream>

using namespace std;

class DLink {
	private:
		int data;
		DLink* next;
		DLink* prev;
	public:
		DLink() {next = NULL; data = 0; prev = NULL;}
		DLink (int x) {next = NULL; data = x; prev = NULL;}

		DLink* getPrev() {return prev;}
		int getData() {return data;}
		DLink* getNext() {return next;}

		void setData (int x) {data = x;}
		void setNext (DLink* nextLink) {next = nextLink;}
		void setPrev (DLink* prevLink) {prev=prevLink;}
};

int main () {
	DLink * one = new DLink(1);  //create four new DLink objects
	DLink * two = new DLink(2);
	DLink * three = new DLink(3);
	DLink * four = new DLink(4);

	one->setNext(two);
	//one->setPrev(NULL);
	two->setNext(three);
	two->setPrev(one);
	three->setNext(four);
	three->setPrev(two);
	//four->setNext(NULL);
	four->setPrev(three);

	for (DLink* i=one; i!=NULL; i=i->getNext()) {
		cout << i->getData() << " ";
		if(i->getNext() == NULL){
			cout << endl;
		}
	}

/*////////////////////////////////////////////////////
	DLink * *myLinks = new DLink*[100];  //create array of pointers

	for (int i = 0; i < 100; i++){
		myLinks[i] = new DLink(i*100);	//create DLink object for each ptr.
										//init to 0, 100, 200, etc.
	}

	for (int i = 0; i<99 ; i++){  //set next ptr for each DLink
		myLinks[i] -> setNext(myLinks[i+1]);
	}

	for (int i =1; i<100; i++){
		myLinks[i] -> setPrev(myLinks[i-1]);
	}

	for (DLink* i=myLinks[0]; i!=NULL; i=i->getNext()) {
		cout << i->getData() << " ";
	}
	cout <<endl;

	for (DLink* i=myLinks[99]; i!=NULL; i=i->getPrev()) {
		cout << i->getData() << " ";
	}
	cout <<endl;
	*/

	return 0;
}
