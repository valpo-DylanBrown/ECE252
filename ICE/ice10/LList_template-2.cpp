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

int main() {
	LList* myList = new LList();
	myList->append(6);
	myList->append(12);
	myList->append(8);
	myList->print();
	cout << "curr element: " << myList->currValue() << endl;
	myList->insert(1);
	myList->next();
	cout << "curr element: " << myList->currValue() << endl;
	myList->print();
	myList->next();
	cout << "curr element: " << myList->currValue() << endl;
	myList->print();
	myList->insert(2);
	myList->insert(3);
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
	myList->prev();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	myList->next();
	cout << "curr element: " << myList->currValue() << endl;
	myList->next();
	myList->print();
	myList->next();
	myList->append(66);
	myList->prev();
	myList->prev();
	myList->append(67);
	myList->insert(44);
	myList->next();
	myList->next();
	myList->prev();
	myList->next();
	myList->print();
	myList->remove();
	myList->remove();
	myList->insert(2);
	myList->insert(3);
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
	myList->insert(2);
	myList->insert(3);
	myList->next();
	myList->next();
	myList->insert(44);
	myList->print();
return 0;
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
	tail = tmp;
}


//case anywhere else
else{
	tmp->setNext(curr->getNext());
	curr->setNext(tmp);

}
size++;

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
	tmp = curr;
	//Case #1: List is empty, nothing to remove.
	if(head == tail){
		cout << "Remove";
		return -9999999;
	}
	//Case #2: Only one item in list.  Remove it.
	//else if(size == 1){
	 else if(head->getNext() == tail){
		free(head->getNext());
		head->setNext(NULL);
		tail = head;
		size--;
		curr = tmp;
	}

	//Case #3:Last item in list.
	else if(tmp->getNext()->getNext() == NULL){
		free(tmp->getNext());
		tmp->setNext(NULL);
		prev();
		curr = tmp;
		size--;
	}

	//Case #4: Nothing is special.  Removing an item from middle of list.
	else{
		free(tmp->getNext());
		tmp->setNext(tmp->getNext()->getNext());
		curr = tmp;
		size--;
	}


};

void LList::next () { // done
	  //check to see if end of list.
		if(curr->getNext() == tail || size == 0){
			return;
		}
	    //if not, advance one item.
		else {
			curr = curr->getNext();
		}
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
	if(curr->getNext() == NULL){ // if tail
		return curr->getData();
	}
	return curr->getNext()->getData();
};

void LList::print (){ // done
	if(size == 0){
		cout << "List Empty" << endl;
	}
	else{
		for(Link* i = head->getNext(); i!=NULL; i = i->getNext()){
			cout << i->getData() << " ";
			if(i->getNext() == NULL){
				cout << endl;
			}
		}
	}
};

int LList::length (){ //done
	return size;
};




// OUTPUT

/*
4c-32-75-9c-9c-29:ice10 dylan$ ./a.out
6 12 8
curr element: 6
curr element: 6
1 6 12 8
curr element: 12
1 6 12 8
1 6 44 3 2 12 8
1 6 44 3 2 12 8
1 6 44 3 2 12 8
curr element: 100
101 100 1 6 44 3 2 12 8 1000 10000
101 100 1 6 44 3 2 12 8 1000 10000
101 100 1 6 500 44 3 2 12 8 1000 10000
101 100 1 6 500 44 3 2 12 8 1000 10000
101 100 1 6 500 44 3 2 12 8 1000 10000
101 100 440 1 6 500 44 3 2 12 8 1000 10000
curr element: 2
101 100 440 1 6 500 44 3 2 12 8 1000 10000
101 100 440 1 6 500 44 3 44 2 12 8 1000 10000 66 67
101 100 440 1 6 500 44 3 44 2 1000 10000 66 67 33
101 100 440 1 6 500 44 3 44 22 2 1000 10000 66 67 33 20
101 100 440 1 6 500 44 3 44 22 2 1000 10000 66 30 -100 33 20 20
101 100 440 1 6 500 44 3 44 22 2 1000 10000 66 30 3 2 44 -100 33 20 20 
*/
