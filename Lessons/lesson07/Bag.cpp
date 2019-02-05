#include<iostream>

using namespace std;


class Bag {

	protected:
	int* data = new int[1000];
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

class BigBag : public Bag{
private:
	int* data;
	int maxSize;
	void resize();
public:
	BigBag();
	bool add(int j);
	int getMaxSize();
};

BigBag:: BigBag(){
	maxSize = 1000;
}
bool BigBag::add(int j) {
	if (size == maxSize){
		resize();
	}
	if(size < maxSize){
		data[size] = j;
		size++;
		return true;
	}
	else{return false;}
}
void BigBag::resize(){
	int newMaxSize = maxSize*2;
	int* oldData;
	int* tmpData;
	oldData = data;
	tmpData = new int[newMaxSize];
	for(int i=0; i<size; i++){
		tmpData[i] = oldData[i];
	}
	delete [] data;
	data = tmpData;
	maxSize = newMaxSize;
}
int BigBag::getMaxSize(){
	return maxSize;
}

int main () {
	BigBag* bag1 = new BigBag();

	bag1->add(-12);
	//cout << bag1->getSize() << endl;
	cout << bag1->contains(-11) << endl << bag1->contains(-12) << endl;
	for(int i=1; i<=2000; i++){
		bag1->add(i);
		//cout << "i = " << i << endl;
		//cout << "MAX: " << bag1->getMaxSize() << endl;
	}
	//cout << "MAX: " << bag1->getMaxSize() << endl	;
	/*for(int i=1; i<=100; i++){
		bag1->remove(i);
	}
	cout << bag1->contains(99) << endl;
	cout << bag1->contains(101) << endl;
	cout << "Size: " << bag1->getSize() << endl;
	for(int i=1; i<=20000; i++){
		bag1->add(i);
	}
	cout << "Size: " << bag1->getSize() << endl;*/
	return 0;
}
