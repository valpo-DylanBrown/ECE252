#include <iostream>
#define LENGTH 10
using namespace std;


void swap(int &x, int &y){
  int tmp = x;
  x = y;
  y = tmp;
}
void printArray(int array[LENGTH]){
  for(int i =0; i<LENGTH; i++){
      cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[LENGTH], int length){
  int count = 0;
  int min;
  for(int i=0; i < length; i++){
    //count++;
    min = i;
    //if(count%10 == 0){
      printArray(array);
    //}
    for(int j=i; j< length; j++){
      if(array[j] < array[min]){
        min = j;
      }
    }
    swap(array[min], array[i]);
  }
}

void fillRandom(int array[LENGTH]){
  for(int i=0; i<100; i++){
    array[i] = rand() % 1000;
  }
}

int main(){
  srand(20);
  //int dataRand[LENGTH];
  //fillRandom(data);
  int data[LENGTH] = {3, 9, 10, 2, 18, 29, 1, 9, 11, 20};
  //printArray(data);
  /*int data1[LENGTH];
  for(int i=0; i<LENGTH; i++){
    data1[i] = i+1;
  }
  int data2[LENGTH];
  for(int i=LENGTH; i>0; i--){
    data2[LENGTH-i] = i;
  }*/
  selectionSort(data, LENGTH);
  printArray(data);

}



/* OUTPUT

*/
