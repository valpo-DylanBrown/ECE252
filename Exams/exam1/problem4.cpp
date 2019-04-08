#include <iostream>
using namespace std;
#define BAGSIZE 1000

class MinMaxBag {
private:
  int * data = new int[BAGSIZE];
  int size;

public:
// default constructor.  Takes no arguments
	MinMaxBag() {
    size = 0;
  }

// adds the integer to the data structure
// if the Bag is full, the function does nothing
// (and does not print an error message)
	void add (int x) {
    if (size == BAGSIZE){
      return;
    }
    data[size] = x;
    size++;
  }

// returns the largest integer from the data
// structure and removes it from the structure
// if the Bag is empty, it returns -1 and does not
// print out any error messages.
	int removeMax () {
    int max = data[0];
    for(int i = 0; i<size; i++){
      if(data[i]>max){
        max = data[i];
      }
    }
    for (int i=0; i<size; i++) {
      if (data[i]  == max) {
        data[i] = data[size-1];
        size--;
        return max;
      }
    }
    return -1;
  }

// returns the smallest integer from the data
// structure and removes it from the structure
// if the Bag is empty, it returns -1 and does not
// print out any error messages.
	int removeMin () {
    int min = data[0];
    for(int i = 0; i<size; i++){
      if(data[i] < min){
        min = data[i];
      }
    }
    for (int i=0; i<size; i++) {
      if (data[i]  == min) {
        data[i] = data[size-1];
        size--;
        return min;
      }
    }
    return -1;
  }
};

int main() {
  //Simple Test ***********************
	MinMaxBag *myBag = new MinMaxBag();
	myBag->add(4);
	myBag->add(3);
	myBag->add(5);
	myBag->add(9);
	cout << "Min: " << myBag->removeMin() << endl;
	cout << "Max: " << myBag->removeMax() << endl;

	delete myBag;
	myBag = new MinMaxBag();


	//Medium Test ***************************
	for (int i=0; i<30; i++) {
		myBag->add(i*2 - 5);
	}
	for (int i=0; i<10; i++) {
		cout << myBag->removeMax() << " ";
	}
	cout << endl;

	for (int i=0; i<10; i++) {
		cout << myBag->removeMin() << " ";
	}
	cout << endl;

	for (int i=0; i<10; i++) {
		myBag->removeMin();
	}

	cout << "Min: " << myBag->removeMin() << endl;
	cout << "Max: " << myBag->removeMax() << endl;

	delete myBag;
	myBag = new MinMaxBag();

	//Full Test ********************************
	for (int i=0; i<400; i++) {
		myBag->add(i*5 - 1000);
	}

	for (int i=0; i<10; i++) {
		myBag->removeMax();
	}
	for (int i=0; i<10; i++) {
		myBag->removeMin();
	}
	for (int i=0; i<6; i++) {
		cout << "Min" << i  << ": " << myBag->removeMin() << endl;
		cout << "Max" << i  << ": " << myBag->removeMax() << endl << endl;
	}

	for (int i=0; i<50; i++) {
		myBag->removeMin();
	}
	cout << "Final Min: " << myBag->removeMin() << endl;
	cout << "Final Max: " << myBag->removeMax() << endl;

	return 0;

}

/*
----------------------------------------------
------------------OUTPUT----------------------
----------------------------------------------
$ a
Min: 3
Max: 9
53 51 49 47 45 43 41 39 37 35
-5 -3 -1 1 3 5 7 9 11 13
Min: -1
Max: -1
Min0: -950
Max0: 945

Min1: -945
Max1: 940

Min2: -940
Max2: 935

Min3: -935
Max3: 930

Min4: -930
Max4: 925

Min5: -925
Max5: 920

Final Min: -670
Final Max: 915

*/
