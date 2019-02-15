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
  Link* first = new Link(1);
  Link* second = new Link(2);
  Link* third = new Link(3);
  Link* fourth = new Link(4);
  Link* fifth = new Link(5);
  first->setNext(second);
  second->setNext(third);
  third->setNext(fourth);
  fourth->setNext(fifth);
  cout << "First List: \n\n";
  for(Link* i = first; i!=NULL; i = i->getNext()){
    cout << i->getData() << endl;
  }
  Link* sixth = new Link(6);
  Link* seventh = new Link(7);
  Link* eigth = new Link(8);
  Link* ninth = new Link(9);
  Link* tenth = new Link(10);
  sixth->setNext(seventh);
  seventh->setNext(eigth);
  eigth->setNext(ninth);
  ninth->setNext(tenth);
  fifth->setNext(sixth);
  cout << "Second List: \n\n";
  for(Link* i = first; i!=NULL; i = i->getNext()){
    cout << i->getData() << endl;
  }
  second->setNext(fourth);
  cout << "Third List \n\n";
  for(Link* i = first; i!=NULL; i = i->getNext()){
    cout << i->getData() << endl;
  }

  Link* ftwo = new Link(42);
  sixth->setNext(ftwo);
  ftwo->setNext(seventh);
  cout << "Fourth List \n\n";
  for(Link* i = first; i!=NULL; i = i->getNext()){
    cout << i->getData() << endl;
  }
  int count;
  for(Link* i = first; i!=NULL; i = i->getNext()){
    count++;
  }
  cout << "Elements in List: " << count << endl;
  // for fun
  /*seventh->setNext(third);
  for(Link* i = first; i!=NULL; i = i->getNext()){
    cout << i->getData() << endl;
  }*/
}
