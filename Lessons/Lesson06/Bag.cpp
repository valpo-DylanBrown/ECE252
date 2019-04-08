#include<iostream>

using namespace std;
#define BAG_CAPACITY 1000

class Bag {

	protected:
	int data[BAG_CAPACITY];
	int size;

	public:

	Bag();



	//adds the element j to the Bag.  Returns true if
	//successfully added, false if the Bag was full.
	bool add(int j);

	// returns true if j is contained in the Bag, false o.w.
	bool contains( int j );

	// removes one instance of j from the Bag.  Returns true
	// if an element is removed, false if the element was not
	// contained in the Bag
	bool remove (int j);

	// returns the number of elements stored in the Bag
	int getSize () { return size; }

	// returns true if there are no elements in the Bag
	bool isEmpty () { return size==0; }



};


Bag::Bag() {
	size = 0;
}

bool Bag::remove( int j) {
	for (int i=0; i<size; i++) {
		if (data[i] == j) {
			//for (int k=i; k<size-1; k++) {
			//	data[k] = data[k+1];
			//}
			data[i] = data[size-1];
			size--;
			return true;
		}
	}
	return false;
}

bool Bag::add(int j) {

	/////CHANGE FOR SET

	if(contains(j)) return false;


	if (size == BAG_CAPACITY) return false;

	data[size] = j;
	size++;
	return true;
}

bool Bag::contains(int j) {
	for (int i=0; i<size; i++) {
		if (data[i] == j) return true;
	}
	return false;
}




int main () {

	Bag *myBag = new Bag();

	cout << "Is bag empty?: " << myBag->isEmpty() << endl;
	myBag->add(6023);
	cout << "Does Bag have 6023?: " << myBag->contains(6023) << endl;
	cout << "Does Bag have 6022?: " << myBag->contains(6022) << endl;



	for (int i=1; i<=25; i++) {
		for (int k=0; k<i; k++) {
			myBag->add(i);
		}

	}

	cout << myBag->remove(1) << endl;

	cout << myBag->contains(1) << endl;
	cout << myBag->remove(1) << endl;

	cout << myBag->contains(1) << endl;
	cout << myBag->remove(2) << endl;

	cout << myBag->contains(2) << endl;
	cout << myBag->remove(2) << endl;

	cout << myBag->contains(2) << endl;

	for (int i=1; i<1000; i++) {
		myBag->add(i);
		if (myBag->getSize() == BAG_CAPACITY) {
			cout << "full at: " << i;
			break;
		}
	}

	return 0;
}
