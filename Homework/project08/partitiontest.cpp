#include <iostream>
using namespace std;
#define SIZE 20
int data[SIZE];

void swap(int x, int y );
void printArray(int numElements);
int partition (int low, int high);
int main(){

  srand(12);
  for(int i=0; i<SIZE; i++){
    data[i] = rand() % 20;
  }
  cout << "ARRAY BEFORE: ";
  printArray(SIZE);
  int p = partition(0,SIZE-1);
  cout << "ARRAY AFTER : ";
  printArray(SIZE);
  cout << endl;
  //cout << "PIVOT: " << p << endl;
}

void swap(int x, int y ) {
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}

void printArray(int numElements){
  for (int i=0; i<numElements; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}
int partition (int low, int high){
	//identify index of pivot value.
  int pivotIndex = (low+high)/2;
  cout << "PIVOT INDEX: " << pivotIndex << "\tValue of:" << data[pivotIndex] << endl;
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
    while(data[leftIndex] <= data[high]){
      leftIndex++;
    }
    while(data[rightIndex] > data[high]){
      rightIndex--;
    }
    //cout << "leftIndex," << leftIndex <<": " << data[leftIndex] << endl;
    //cout << "rightIndex," << rightIndex <<": " << data[rightIndex] << endl;
    //printArray(SIZE);
    if(leftIndex<=rightIndex){
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
