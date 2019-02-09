#include <iostream>
#include "Bag.h"
using namespace std;
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
		if (myBag->getSize() == 1000) {
			cout << "full at: " << i;
			break;
		}
	}

	return 0;
}
