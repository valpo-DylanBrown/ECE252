#include "Queue.h"
#include <iostream>
using namespace std;


QArray::QArray(){
	size=0;
	start=0;
	tail=0;
}

bool QArray::enqueue(int j){
	if (size==MAXSIZE) return false;	//is queue full?
	
	elements[tail]=j;  //actually places the new number in the queue.
	
	tail++;  //increment location for next data.
	tail %=  MAXSIZE;  //handle wrap-around for tail.
	//tail=tail%MAXSIZE;
	
	size++;
	
	return true;  //number successfully enqueued
}
		
int QArray::dequeue(){
	if (isEmpty()) return -1;  //-1 indicates an invalid value.
	
	int temp=elements[start]; //making a temporary copy of the value to be returned.
	
	size--;  //one less element in the queue.
	start++;  //points to the newest oldest value.
	
	start %= MAXSIZE;  //handles wrap-around of start.	
	
	return temp;
}
		
int QArray::getSize(){
	return size;
}
		
int QArray::getFirst(){
	if (tail==0) return elements[MAXSIZE];
	else return elements[tail-1];
}
		
bool QArray::isEmpty(){
	return (size==0);
}
		
		
	
	
  