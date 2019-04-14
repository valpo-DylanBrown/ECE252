#include <iostream>
using namespace std;

#define MAXSIZE 100

class IntStack {
	private:
		int stackArray[MAXSIZE]; //contains actual characters in stack.
		int size; 	//contains the current number of characters on stack.

	public:
		IntStack();  //constructor
		void push (int x);
		bool isFull();
		int pop();  //look and remove
		bool isEmpty();
		int top();  //look but don't touch
};


	IntStack::IntStack(){
		size = 0;
	}

   void IntStack::push(int x) {
		 if(isFull()){
			 cout << "Error stack is full." << endl;
			 return;
		 }
		 stackArray[size] = x;
		 size++;
   }

   bool IntStack::isFull () {
		 if(size == MAXSIZE){
			 return true;
		 }
		 else{return false;}

   }

   int IntStack::pop() {
		 if(isEmpty()){
			 cout << "Error stack is empty." << endl;
			 return 0;
		 }
		 size--;
		 return stackArray[size];
   }

   bool IntStack::isEmpty() {
		 if(size == 0){
			 return true;
		 }
		 else{return false;}
   }

   int IntStack::top() {
		 if(isEmpty()){
			 return 0;
		 }
		 return stackArray[size-1];
   }




int main(int argc, char* argv[])
{
  IntStack myStack;
  myStack.push(5);
  myStack.push(4);
	myStack.push(7);
  cout << "Remove: " << myStack.pop() << endl;
	myStack.push(11);
  myStack.push(5);
	myStack.push(2);
  cout << "Pop: " << myStack.pop() << endl;
	cout << "Remove: " << myStack.pop() << endl;
  myStack.push(12);
  myStack.push(3);
  cout << "Pop: " << myStack.pop() << endl;
  
}
