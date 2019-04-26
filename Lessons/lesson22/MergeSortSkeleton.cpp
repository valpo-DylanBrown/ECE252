#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#define MAXVALUE 1000
#define MAXSIZE 200000000

void swap(int x, int y );
void mergeSort(int left, int right);
void merge(int left, int middle, int right);
void randomArray(int numElements, int seed);
void printArray(int numElements);

int data[MAXSIZE];  //global variable
int temp[MAXSIZE];	//global variable

int main (int argc, char *argv[]){

	int numElements=atoi(argv[1]);
	int seed=137;
	time_t timerStart;
	time_t timerStop;
	float elapsedTime;

	randomArray(numElements, seed);
	printArray(numElements);

	//cout << "Merge sorting " << numElements << " elements:" << endl;
	timerStart=clock();  //Start keeping track of time
	mergeSort(0, numElements-1);
	timerStop=clock();   //Stop keeping track of time.

	elapsedTime=((float)timerStop-(float)timerStart)/CLOCKS_PER_SEC;
	//cout << "Elapsed Time=" << elapsedTime << " seconds"<< endl<< endl;

	printArray(numElements);
	return 0;
}

void mergeSort(int left,int right){
 //insert your mergeSort code here.
}

void merge(int left,int middle,int right){
//insert your merge() code here.
	
}

//Prints the contents of an array, separated by spaces
void printArray(int numElements){
	for (int i=0; i<numElements; i++){
		cout << data[i] << " ";
	}
	cout << endl;
}

//Fills array data with numElements of random numbers, using seed
void randomArray(int numElements, int seed){
	//fill array with random numbers
	srand(seed);
	for (int i=0; i<numElements; i++ ) {
		data[i]= rand()%MAXVALUE;
	}
}


// Swaps the elements in data[x] and data[y]
void swap(int x, int y ) {
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}
