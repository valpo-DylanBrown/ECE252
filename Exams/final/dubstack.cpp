#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 1000

class DubStack {
private:
  int data[MAXSIZE];
  int stackA;
  int stackB;
  //int size;
  int sizeA;
  int sizeB;

public:
  //constructor
  DubStack();

  //pushes elemtns onto stacks A or B
  void pushA(int x);
  void pushB(int x);

  //pops elemtns from stacks A or B
  int popA();
  int popB();

  //checks to see if stacks are empty
  bool isAEmpty();
  bool isBEmpty();


  bool isFull();
};

DubStack::DubStack(){
    for(int i = 0; i<MAXSIZE; i++){
      data[i] = 0;
    }
    stackA = -1;
    stackB = MAXSIZE;
    sizeA = 0;
    sizeB = 0;
}
bool DubStack::isAEmpty(){
  return(sizeA == 0);
}
bool DubStack::isBEmpty(){
  return(sizeB == 0);
}

bool DubStack::isFull(){
  return (sizeA+sizeB == MAXSIZE);
}

void DubStack::pushA(int x){
  if(!isFull()){
    stackA++;
    data[stackA] = x;
    sizeA++;
  }
  else{
    cout << "error, overflow on stackA" << endl << endl << endl;
  }
}
void DubStack::pushB(int x){
  if(!isFull()){
    stackB--;
    data[stackB] = x;
    sizeB++;
  }
  else{
    cout << "error, overflow on stackB" << endl << endl << endl;
  }
}

int DubStack::popA(){
  if(stackA>=0){
    int val = data[stackA];
    stackA--;
    sizeA--;
    return val;
  }
  else{
    cout << "error, empty stackA" << endl << endl << endl;
    return -9999;
  }

}
int DubStack::popB(){
  if(stackB<MAXSIZE){
    int val = data[stackB];
    stackB++;
    sizeB--;
    return val;
  }
  else{
    cout << "error, empty stackB" << endl << endl << endl;
    return -9999;
  }
}

int main() {

	//DubStack,
	DubStack * simpleStack = new DubStack();
	DubStack * medStack = new DubStack();
	DubStack * hardStack = new DubStack();

	//Simple test for DubStack
	simpleStack->pushA(1);
	simpleStack->pushA(2);
	simpleStack->pushA(3);
	simpleStack->pushB(4);
	simpleStack->pushB(5);
	simpleStack->pushB(6);

	cout << "Checking Simple Stack: " << endl;
	cout << "A pop: " << simpleStack->popA() << endl;
	cout << "B pop: " << simpleStack->popB() << endl << endl;



	//Medium Test for DubStack --> pushes 100 integers onto each stack
	for (int i=0; i<100; i++) {
		medStack->pushA(i+1);
		medStack->pushB(-2*i+1);
	}

	cout << "Checking Medium Stack: " << endl;
	cout << "Is A Empty? " << medStack->isAEmpty() << endl;
	cout << "Is B Empty? " << medStack->isBEmpty() << endl;
	cout << "A pop: " << medStack->popA() << endl;
	cout << "B pop: " << medStack->popB() << endl;

	for (int i=0; i<98; i++) {
		medStack->popA();
		medStack->popB();
	}

	cout << "A pop: " << medStack->popA() << endl;
	cout << "B pop: " << medStack->popB() << endl;
	cout << "A pop: " << medStack->popA() << endl;
	cout << "B pop: " << medStack->popB() << endl << endl;


	//Complete Test for DubStack

	//put 100 integers onto stackA, 900 onto StackB
	for (int i=0; i<100; i++) {
		hardStack->pushA(i);
	}
	for (int i=0; i<900; i++) {
		hardStack->pushB(i);
	}


	cout << "Checking Hard Stack: " << endl;
	cout << "A pop: " << hardStack->popA() << endl;
	cout << "B pop: " << hardStack->popB() << endl;

	//now over-fill it
	hardStack->pushA(1001);
	hardStack->pushA(2001);
	hardStack->pushA(3001);
	hardStack->pushA(4001);

	//now just put it through its paces...
	for (int i=0; i<50; i++) {
		hardStack->popA();
	}
	for (int i=0; i<50; i++) {
		hardStack->popB();
	}
	for (int i=0; i<100; i++) {
		hardStack->pushA(i);
	}
	for (int i=0; i<150; i++) {
		hardStack->popA();
	}
	for (int i=0; i<800; i++) {
		hardStack->popB();
	}

	cout << "Is A Empty? " << hardStack->isAEmpty() << endl;
	cout << "Is B Empty? " << hardStack->isBEmpty() << endl;
	cout << "A pop: " << hardStack->popA() << endl;
	cout << "B pop: " << hardStack->popB() << endl;
	cout << "Is A Empty? " << hardStack->isAEmpty() << endl;
	cout << "Is B Empty? " << hardStack->isBEmpty() << endl;

}
