#ifndef CHARSTACK_H
#define CHARSTACK_H

#define MAXSIZE 100

class CharStack {
	private:
		char stackArray[MAXSIZE]; //contains actual characters in stack.
		int size; 	//contains the current number of characters on stack.
	
	public:
		CharStack();  //constructor
		void push (char x);
		bool isFull();  
		char pop();  //look and remove
		bool isEmpty();
		char top();  //look but don't touch
};

#endif
