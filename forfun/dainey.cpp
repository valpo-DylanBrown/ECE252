#include <iostream>
#include <time.h>

#define SIZE 12
using namespace std;
void printArray(int array[SIZE],int j){
  cout << "Trial " << j+1 << ": ";
  for(int i = 0; i<SIZE; i++){
    cout << array[i] << " ";
  }
};
int main(){
  srand(time(NULL));
  int array[SIZE];
  int j = 0;
  while(j < 100){
    /*
    for(int i = 0; i<SIZE; i++){
      array[i] = rand() %20 +1;
    }
    cout << "Trial " << j+1 << ": ";
    for(int i = 0; i<SIZE; i++){
      cout << array[i] << " ";
    }*/
    for (int i=0;i<SIZE;i++){
    bool check; //variable to check or number is already used
    int n; //variable to store the number in
    do
    {
    n=rand()%20+1;
    //check or number is already used:
    check=true;
    for (int j=0;j<i;j++)
        if (n == array[j]) //if number is already used
        {
            check=false; //set check to false
            break; //no need to check the other elements of value[]
        }
    } while (!check); //loop until new, unique number is found
    array[i]=n; //store the generated number in the array
  }
  printArray(array,j);
    cout << endl;
    j++;
  }
}
