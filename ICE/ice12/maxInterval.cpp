#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


void maxInterval1(int* data, int size) {
	int minIndex;
	int maxIndex;
	int maxSum = 0;
	int sum = 0;

	for(int i = 0; i<size; i++){
		//cout << "I: " << i;
		for(int j = i; j<size; j++){
			//cout << " J: " << j;
			for(int k=i; k<=j; k++){
				//cout << " K: " << k << endl;
				sum+=data[k];
				//cout << "Sum: " << sum << endl;
				}
				if(sum>maxSum){
					maxSum = sum;
					minIndex = data[i];
					maxIndex = data[j];
				}
				sum = 0;
			}
	}

	/*	if(sum > maxSum){
			maxSum = sum;
			minIndex = data[k];
			maxIndex = data[j];*/

	cout << "The maximum sum is: " << maxSum << " which occurs between " << minIndex << " and " << maxIndex << endl;
}

void maxInterval2(int* data, int size) {

	int minIndex;
	int maxIndex;
	int maxSum;


	cout << "The maximum sum is: " << maxSum << " which occurs between " << minIndex << " and " << maxIndex << endl;

}


int main ( int argc, char *argv[] ) {

	if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        printf( "usage: %s <size of array>\n", argv[0] );
		return 0;
    }

	//create and fill array **********
	int n = atoi(argv[1]);
	int* dataArray = new int[n];
	srand(n);
	dataArray;
	for (int i=0; i < n; i++) {
		dataArray[i] = (rand()%201) - 100; // create -100 to 100

	}
	for (int i=0; i < n; i++) {
		cout << dataArray[i] << endl;
	}
	//*************************

	clock_t t;
    t = clock();  //set up and start clock

	maxInterval1(dataArray, n);  // call the function of interest

	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // stop clock

    printf("The function took %f seconds to execute \n", time_taken);

	return 0;
}
