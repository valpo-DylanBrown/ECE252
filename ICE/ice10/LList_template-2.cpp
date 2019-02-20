#include <stdlib.h>
#include <iostream>

using namespace std;

class Link {   //singly-linked list, only points to next object in list.

	private:
		int data;
		Link* next;
	public:
		Link() {next = NULL; data = 0; }
		Link (int x) { next = NULL; data = x; }

		int getData() { return data; }
		Link* getNext() { return next; }

		void setData (int x) { data = x; }
		void setNext (Link* nextLink) { next = nextLink; }

};

class LList {

	private:
		Link* head;  //head is the first item in the list
		Link* tail;  //tail is the last item in the list
		Link* curr;  //curr points to the element _before_ the "current" link.
		int size;
	public:
		LList () { head = new Link();tail = head; curr = head; size = 0;}  //default constructor
		void insert ( int x ); //inserts a new node before the current element
		void append ( int x ); //inserts a new node at the end of the list
		int remove (); //removes the current node
		void next (); //moves the current node one element toward end of list
		void prev (); //moves the current node one element toward start of list
		int currValue (); //returns value of current node
		void print (); //prints every element list with spaces between
		int length ();  //returns number of elements in list.
};

int main() {  	//This is sample input, which you can use to check your code


	LList* myList = new LList();
	myList->append(2);
	myList->append(3);
	myList->append(4);
	myList->print();
	cout << "LENGTH: " << myList->length() << endl;
	//cout << "curr element: " << myList->currValue() << endl;
	myList->next();
	cout << "curr element: " << myList->currValue() << endl;
	myList->insert(1);
	//myList->insert(2);
	//myList->insert(3);
	//myList->next();
	myList->print();
	cout << "curr element: " << myList->currValue() << endl;
	myList->remove();
	myList->print();
	cout << "curr element: " << myList->currValue() << endl;
	myList->next();
	cout << "curr element: " << myList->currValue() << endl;
	/*
	myList->append(6);
	myList->append(12);
	myList->append(8);
	myList->print();
	cout << "curr element: " << myList->currValue() << endl;
	myList->insert(1);
	myList->insert(2);
	myList->insert(3);
	myList->next();
	myList->print();
	myList->next();
	myList->print();
	myList->insert(44);
	myList->print();
	myList->prev();
	myList->print();
	myList->prev();
	myList->print();
	myList->insert(100);
	myList->insert(101);
	myList->next();
	myList->append(1000);
	myList->append(10000);
	cout << "curr element: " << myList->currValue() << endl;
	myList->print();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->print();
	myList->insert(500);
	myList->print();
	myList->prev();
	myList->print();
	myList->prev();
	myList->print();
	myList->insert(440);
	myList->print();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	cout << "curr element: " << myList->currValue() << endl;
	myList->next();
	myList->print();
	myList->insert(-42);
	myList->next();
	myList->next();
	myList->append(66);
	myList->prev();
	myList->prev();
	myList->append(67);
	myList->insert(44);
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->print();
	myList->remove();
	myList->remove();
	myList->remove();
	myList->remove();
	myList->append(33);
	myList->print();
	myList->prev();
	myList->insert(22);
	myList->append(20);
	myList->print();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->remove();
	myList->insert(30);
	myList->next();
	myList->insert(-100);
	myList->append(20);
	myList->print();

return 0;
*/
}


void LList::insert ( int x ){
/*
1) Create new link (Link* tmp = new(x);)
2) Set next of element of curr to tmp
3) Point tmp to curr
3) set curr to tmp
*/
Link* tmp = new Link(x);
//case at start
if(head->getNext() == NULL){
	head->setNext(tmp);
}


//case anywhere else
else{
	tmp->setNext(curr->getNext());
	curr->setNext(tmp);
}


};

void LList::append ( int x ){ //done

	/*
	1) Create new link of x
	2) Set tail's next to new link
	3) set tail to new link
	*/
	Link* tmp = new Link(x);
	tail->setNext(tmp);
	tail = tmp;
	size++;
};

int LList::remove (){
	Link* tmp = new Link();
	Link* next = new Link();
	tmp = curr;
	next = tmp->getNext()->getNext();
	//Case #1: List is empty, nothing to remove.

	//Case #2: Only one item in list.  Remove it.


	//Case #3:Last item in list.
	/*if(tmp == tail){
		prev();
		tmp->getNext()->setNext(NULL);
		free(tmp->getNext());
		prev();
		curr = tmp;
	}*/

	//Case #4: Nothing is special.  Removing an item from middle of list.
//else{
	free(tmp->getNext());
	tmp->setNext(next);
	curr = tmp;
//}



};

void LList::next () { // done
	  //check to see if end of list.
		if(curr->getNext() == tail || size == 0){
			return;
		}
	    //if not, advance one item.
		curr = curr->getNext();
	return;
};

void LList::prev () { // done
	if(size == 0 || size == 1){
		return;
	}
	for(Link* i = head; i!=curr->getNext(); i = i->getNext()){
		if(i->getNext() == curr){
			curr = i;
		}
	}
	return;
};

int LList::currValue () { // done
	if(size == 0){ //list empty
		return -9999999;
	}
	/*Link* actualCurr = curr->getNext();
	return actualCurr->getData();*/
	if(curr == tail){
		return curr->getData();
	}
	return curr->getNext()->getData();
};

void LList::print (){ // done
	for(Link* i = head->getNext(); i!=NULL; i = i->getNext()){
		cout << i->getData() << " ";
		if(i->getNext() == NULL){
			cout << endl;
		}
	}
};

int LList::length (){ //done
	return size;
};
