#include "QueueSkeleton.h"
#include <iostream>
using namespace std;


QArray::QArray(){
	size = 0;
}

bool QArray::enqueue(int j){
	if(size == MAXSIZE){
		return false;
	}
	element[size] = j;
	size++;
	return true;
}


int QArray::dequeue(){
	int retVal = element[0];
	if(size == 0){
		return -1;
	}
	for(int i =0; i<size; i++){
		element[i] = element[i+1];
	}
	size--;
	return retVal;
}


int QArray::getSize(){
	return size;
}

int QArray::getFirst(){
	if(size == 0){
		return -1;
	}
	return element[0];
}

bool QArray::isEmpty(){
	/*if(size == 0){
		return true;
	}
	return false;*/
	return (size == 0);
}
