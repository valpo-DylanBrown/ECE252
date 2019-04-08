#include<iostream>

using namespace std;


class Bag {

	protected:
	int* data;
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

class BigBag : public Bag{
public:
	int bagSize;
	BigBag(){
		bagSize = 1000;
		data = new int[bagSize];
		size = 0;
	}
	int getBagSize(){
		return bagSize;
	}
	bool add(int j){
		if (size==bagSize){
			bagSize = bagSize*2;
			int* tmpData = new int[bagSize];
			for(int i=0; i<size; i++){
				tmpData[i] = data[i];
			}
			delete [] data;
			data = tmpData;
		}
		data[size] = j;
		size++;
		return true;
	}
};

Bag::Bag() {
	size = 0;
}

bool Bag::remove( int j) {
	for (int i=0; i<size; i++) {
		if (data[i] == j) {
			for (int k=i; k<size-1; k++) {
				data[k] = data[k+1];
			}
			size--;
			return true;
		}
	}
	return false;
}

bool Bag::add(int j) {




	if (size == 1000) return false;

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

	BigBag* bb1 = new BigBag();

	bb1->add(-12);
	cout << "-11?\t" << bb1->contains(-11) << endl << "-12?\t" << bb1->contains(-12) << endl;
	cout << "Adding 1 to 20,000" << endl;
	for(int i=1; i<=20000; i++){
		bb1->add(i);
	}
	cout << "Removing 1 to 100" << endl;
	for(int i=1; i<=100; i++){
		bb1->remove(i);
	}
	cout << "99?\t" << bb1->contains(99) << endl << "101?\t" << bb1->contains(101) << endl;
	cout << "Size:\t" << bb1->getSize() << endl;
	cout << "Adding 1 to 20,000" << endl;
	for(int i=1; i<=20000; i++){
		bb1->add(i);
	}
	cout << "Size:\t" << bb1->getSize() << endl;
	cout << "10,000?\t" << bb1->contains(10000) << endl << "21,000?\t" << bb1->contains(21000) << endl;
	cout << "Removed 997?\t" << bb1->remove(997) << endl;
	cout << "997?\t" << bb1->contains(997) << endl;
	cout << "Removed 997?\t" << bb1->remove(997) << endl;
	cout << "997?\t" << bb1->contains(997) << endl;

	return 0;
}


//*********************
//OUTPUT
//*********************
/*
4c-32-75-9c-9c-29:ice07 dylan$ ./a.out
-11?	0
-12?	1
Adding 1 to 20,000
Removing 1 to 100
99?	0
101?	1
Size:	19901
Adding 1 to 20,000
Size:	39901
10,000?	1
21,000?	0
Removed 997?	1
997?	1
Removed 997?	1
997?	0
*/
