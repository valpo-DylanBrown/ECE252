#include <iostream>
#define SIZE 1000

using namespace std;


class Bag{

	protected:
	//int data[currentsize];
	int* data;

	public:
	int k;
	int currentsize;
	Bag();
	~Bag();
	bool add(int j);
	bool contains(int j);
	bool remove(int j);
	int getSize();
	bool isEmpty();
	void printBag();

	bool isFull();


};



Bag::Bag(){
	k = 0;
	currentsize = 1000;
	data = new int[currentsize];
}
Bag::~Bag(){
	delete [] data;
}
