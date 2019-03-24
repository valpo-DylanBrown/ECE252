#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


void maxInterval1(int* data, int size) {
	int minIndex;
	int maxIndex;
	int maxSum = 0;
	
	int tmpSum = 0;
	
	for (int i=0; i<size; i++) {
		for (int j=i; j<size; j++) {
		  tmpSum = 0;
		  for (int k=i; k<=j; k++) {
			tmpSum += data[k];
		  }
		  if (tmpSum > maxSum) {
			maxSum = tmpSum;
			minIndex = i;
			maxIndex = j;
			//printf("new max: %d,%d,%d\n", tmpSum, i, j);
		  }
		}
	}
	
	cout << "The maximum sum is: " << maxSum << " which occurs between " << minIndex << " and " << maxIndex << endl;
}

void maxInterval2(int* data, int size) {

	int minIndex;
	int maxIndex;
	int maxSum;
	
	
	cout << "The maximum sum is: " << maxSum << " which occurs between " << minIndex << " and " << maxIndex << endl;

}

/* void maxInterval3(int* data, int size) {

	int startIndex=0,endIndex=0;

   int max_so_far=0;
   int max_sum=-999;
   
   for(int i=0;i<size;i++)
   {
   max_so_far=max_so_far+data[i];//kadane's algorithm step 1
   if(max_so_far>max_sum) //computing max
   {
      max_sum=max_so_far;
      endIndex=i;
   }

   if(max_so_far<0)
   {
   max_so_far=0;
   startIndex=i+1;
   }

	}
	
	cout << "The maximum sum is: " << max_so_far << " which occurs between " << startIndex << " and " << endIndex << endl;

} */


void maxIntervalKadane(int a[], int size)
{
    int max_so_far = -9999, max_ending_here = 0;
	int startIndex = 0;
	int endIndex = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
			endIndex = i;
		}
 
        if (max_ending_here < 0) {
            max_ending_here = 0;
			startIndex = i+1;
		}
    }
    cout << "The maximum sum is: " << max_so_far << " which occurs between " << startIndex << " and " << endIndex << endl;
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
	for (int i=0; i < n; i++) {
		dataArray[i] = (rand()%201) - 100; // create -100 to 100
		//cout << dataArray[i] << " ";
	}
	cout << endl;
	//*************************
	
	clock_t t;
    t = clock();  //set up and start clock
	
	//maxInterval3(dataArray, n);  // call the function of interest
	maxIntervalKadane(dataArray, n);
	
	//int newData[9] = {-2, 1, -2, 4, -3, 5, -4, -3, 5};
	//maxIntervalKadane(newData, 9);
    
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // stop clock
 
    printf("The function took %f seconds to execute \n", time_taken);
	
	return 0;
}