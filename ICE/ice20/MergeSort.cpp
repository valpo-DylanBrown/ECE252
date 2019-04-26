#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#define MAXVALUE 1000
#define MAXSIZE 200000000

//void swap(int x, int y );
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
	if(left==right) return;

	if(left<right) {
		int m = (left+right) / 2;
		mergeSort(left, m);
		mergeSort(m+1, right);
		merge(left, m, right);
	}
}

void merge(int left,int middle,int right){
//insert your merge() code here.
/*
	int leftPos, rightPos, tmpPos;
	leftPos = left;
	rightPos = middle + 1;
	tmpPos = left;
	int left1 = middle-left+1;
	int right1 = right - middle;
	int leftTemp[left1];
	int rightTemp[right1];

	for(int i=0; i<left1; i++) {
		leftTemp[i] = temp[left+i];
	}
	for(int i=0; i<right1; i++) {
		rightTemp[i] = temp[middle+right+i];
	}

	while(left < left1 && right < right1) {
		if(leftTemp[leftPos] <= rightTemp[rightPos]) {
			temp[tmpPos] = leftTemp[leftPos];
			leftPos++;
		} else {
			temp[tmpPos] = rightTemp[rightPos];
			rightPos++;
		}
		tmpPos++;
	}
	int j, k;
	while(j < left1) {
		temp[tmpPos] = leftTemp[j];
		j++;
		tmpPos++;
	}

	while(k < right1) {
		temp[tmpPos] = rightTemp[k];
		k++;
		tmpPos++;
	}
	*/
	//int leftPos, rightPos, tmpPos;
	int leftLength = middle-left+1;
	int rightLength = right-middle;
	int i,j,k;

	int L[leftLength], R[rightLength];

	for(i = 0; i<leftLength; i++){
		L[i] = data[left+i];
	}
	for(j = 0; j<rightLength; j++){
		R[j] = data[middle+1+j];
	}
	i =0;
	j = 0;
	k = left;

	while(i < leftLength && j < rightLength){
		if(L[i] <= R[j]){
			data[k] = L[i];
			i++;
		}
		else{
			data[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < leftLength){
		data[k] = L[i];
		i++;
		k++;
	}

	while(j < rightLength){
		data[k] = R[j];
		j++;
		k++;
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

/*
// Swaps the elements in data[x] and data[y]
void swap(int x, int y ) {
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}
*/
