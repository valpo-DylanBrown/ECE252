#include <stdlib.h>
#include <iostream>

using namespace std;

class Link {   //singly-linked list, only points to next object in list.

	private:
		int data;
		Link* next;
	public:
		Link() { next = NULL; data = 0; }
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

	public:
		LList () { head = new Link(); tail = head; curr = head;}  //default constructor
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
				//using sample output (on Blackboard).  Then switch to testbench code
				//before submitting assignment.

	LList* myList = new LList();
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

} 


void LList::insert ( int x ){

};

void LList::append ( int x ){	

};

int LList::remove (){
	//Case #1: List is empty, nothing to remove.
	
	//Case #2: Only one item in list.  Remove it.

	
	//Case #3:Last item in list.

	
	//Case #4: Nothing is special.  Removing an item from middle of list.


};

void LList::next () {	
	  //check to see if end of list.
	    //if not, advance one item.
		
	return;
};
   
void LList::prev () {

};

int LList::currValue () {
	
};

void LList::print (){

};

int LList::length (){

};
