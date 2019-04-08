#include <iostream>
#include <time.h>
using namespace std;
#define SIZE 61
#define TIMEUNTIL 300

void delay(unsigned int mseconds){
  clock_t goal = mseconds + clock();
  while (goal > clock());
}

int main(){
  srand(time(NULL));
  string distance[SIZE];
  int index = 21;
  int x = 0;
  for(int i = 0; i<SIZE; i++){
    distance[i] = ".";

  }
  distance[index] = "X";
  for(int i = 0; i<SIZE; i++){
    cout << distance[i] << " ";
  }
  for(int i = 0; i<TIMEUNTIL; i++){
    if(i == TIMEUNTIL-1){
      cout << "Oh, rats - the concert is over." << endl;
      break;
    }
    x = rand()%2;
    if(x == 1){
      if(index == SIZE-1){
        cout << "Baby, Let the games begin." << endl;
        break;
      }
      index++;

    }
    else{
      if(index == 0){
        cout << "The wolverines feast on the tender flesh of Prof. El-Howayek" << endl;
        break;
      }
      index--;
    }
    for(int i = 0; i<SIZE; i++){
      distance[i] = ".";
    }
    distance[index] = "X";
    for(int i = 0; i<SIZE; i++){
      delay(50);
      cout << distance[i] << " ";
    }
    cout << endl;
  }
}
