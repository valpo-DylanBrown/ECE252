#include "CharStack.h"
#include <iostream>
using namespace std;


	CharStack::CharStack(){
		size = 0;
	}

   void CharStack::push(char x) {
		 if(isFull()){
			 cout << "Error stack is full." << endl;
			 return;
		 }
		 stackArray[size] = x;
		 size++;
   }

   bool CharStack::isFull () {
		 if(size == MAXSIZE){
			 return true;
		 }
		 else{return false;}

   }

   char CharStack::pop() {
		 if(isEmpty()){
			 cout << "Error stack is empty." << endl;
			 return 0;
		 }

		 size--;
		 return stackArray[size];
   }

   bool CharStack::isEmpty() {
		 if(size == 0){
			 return true;
		 }
		 else{return false;}
   }

   char CharStack::top() {
		 if(isEmpty()){
			 return 0;
		 }
		 return stackArray[size-1];
   }
