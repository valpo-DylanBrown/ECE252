#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#define MAXVALUE 1000

void swap( int * data, int x, int y );
void shellSort(int * data, int numElements);
void randomArray(int * data, int numElements, int seed);
void printArray(int * data, int numElements);


int main (int argc, char *argv[]){
	
	int numElements=atoi(argv[1])*1000;
	int seed=137;
	int * data;
	
	data=(int *)malloc(numElements*sizeof(int)); //allocate memory
	randomArray(data, numElements, seed); 
	//printArray(data,numElements);
	shellSort(data, numElements);
	//printArray(data,numElements);
	free(data);

	return 0;
}


//Uses insertion sort algorithm to sort array data of numElements
void shellSort (int * data, int numElements) {
	time_t timerStart;
	time_t timerStop;
	float elapsedTime; 
	int temp, j;
	cout << "Shell sorting " << numElements << " elements:" << endl;
	timerStart=clock();  //Start keeping track of time
	
		
	//Start at skip=numElements/2, go down to 1.
	for (int skip=numElements/2; skip >0; skip=skip/2){
         //i represents how many elements are sorted
		 for (int i=skip; i<numElements; i++){
			int temp=data[i];
			//j represents current location in sorted region.
			for (j=i;(j>=skip) && (temp <data[j-skip]); j-=skip){
				data[j] = data[j-skip];
			}
			data[j]=temp;
		}
	}
	
	timerStop=clock();   //Stop keeping track of time.	

	elapsedTime=((float)timerStop-(float)timerStart)/CLOCKS_PER_SEC;
	cout << "Elapsed Time=" << elapsedTime << " seconds"<< endl<< endl;
}

//Prints the contents of an array, separated by spaces
void printArray(int * data, int numElements){
	for (int i=0; i<numElements; i++){
		cout << data[i] << " ";
	}
	cout << endl;
}

//Fills array data with numElements of random numbers, using seed 
void randomArray(int * data, int numElements, int seed){
	//fill array with random numbers
	srand(seed);
	for (int i=0; i<numElements; i++ ) {
		data[i]= rand()%MAXVALUE;
	}
}


// Swaps the elements in data[x] and data[y]
void swap( int * data, int x, int y ) {
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}

