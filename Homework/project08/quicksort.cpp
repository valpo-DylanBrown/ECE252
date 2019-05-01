#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#define MAXVALUE 1000
#define MAXSIZE 200000000 // this will change by the size of the array you want to use

void swap(int x, int y );
void randomArray(int numElements, int seed);
void printArray(int numElements);
int partition (int low, int high);
void quickSort(int low, int high);

int data[MAXSIZE];  //global variable
//int data[20];
int temp[MAXSIZE];	//global variable

int main (int argc, char *argv[]){

  int numElements=atoi(argv[1]);
	int seed=137;
	time_t timerStart;
	time_t timerStop;
	float elapsedTime;
	randomArray(numElements, seed);
  printArray(numElements);

	cout << "Quick sorting " << numElements << " elements:" << endl;
  quickSort(0, numElements-1);
	/*timerStart=clock();  //Start keeping track of time
	quickSort(0, numElements-1);
	timerStop=clock();   //Stop keeping track of time.

	elapsedTime=((float)timerStop-(float)timerStart)/CLOCKS_PER_SEC;
	cout << "Elapsed Time=" << elapsedTime << " seconds"<< endl<< endl;
*/
	printArray(numElements);
	return 0;
}

int partition (int low, int high){
	//identify index of pivot value.
  int pivotIndex = (low+high)/2;
  //cout << "PIVOT INDEX: " << pivotIndex << "\tValue of:" << data[pivotIndex] << endl;
	//swap pivot value with right end.
  swap(pivotIndex, high);
	//Initialize leftIndex and rightIndex
  int leftIndex = low;
  int rightIndex = high-1;

  //cout << "leftIndex," << leftIndex <<": " << data[leftIndex] << endl;
  //cout << "rightIndex," << rightIndex <<": " << data[rightIndex] << endl;
	//march the two indexes toward each other, swapping each time you find an inversion.
	// Stop when the two values cross.
  while(leftIndex<=rightIndex){
    while(leftIndex<=rightIndex && data[leftIndex] <= data[high]){
      leftIndex++;
    }
    while(leftIndex<=rightIndex && data[rightIndex] > data[high]){
      rightIndex--;
    }
    //cout << "leftIndex," << leftIndex <<": " << data[leftIndex] << endl;
    //cout << "rightIndex," << rightIndex <<": " << data[rightIndex] << endl;
    //printArray(SIZE);
    if(leftIndex<rightIndex){
      swap(leftIndex,rightIndex);
    }
    //printArray(SIZE);
  }
	//reset pivot index to put the pivot back in place (in the middle of the two subarrays)
  pivotIndex = leftIndex;
  swap(pivotIndex, high);

	//return the pivot _index_ value to tell the calling function where the two sub-arrays split.
  return pivotIndex;
}

void quickSort(int low, int high){
	//  Insert your quick sort code here.
  //if(high-low <= 0) return;
  if(low < high){
    int pivot = partition(low, high);
    quickSort(low, pivot-1);
    quickSort(pivot+1, high);
  }

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
