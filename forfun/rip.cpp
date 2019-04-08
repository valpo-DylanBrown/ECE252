#include <iostream>
#include <time.h>
using namespace std;
#define SIZE 61
#define TIMEUNTIL 1000

void delay(unsigned int mseconds){
  clock_t goal = mseconds + clock();
  while (goal > clock());
}

int main(){
  srand(time(NULL));
  string distance[SIZE];
  int index = 21;
  int x = 0;
  cout << "Me trying to pass the semester";
  for(int i = 0; i<SIZE; i++){
    distance[i] = ".";

  }
  distance[index] = "X";
  for(int i = 0; i<SIZE; i++){
    cout << distance[i] << " ";
  }
  cout << "Me procrastinating";
  cout << endl;
  for(int i = 0; i<TIMEUNTIL; i++){
    if(i == TIMEUNTIL-1){
      cout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
      cout << "                     lmao, rip, cant decide." << endl;
      cout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
      break;
    }
    x = rand()%2;
    if(x == 1){
      if(index == SIZE-1){
        cout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
        cout << "                     dumbass." << endl;
        cout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
        break;
      }
      index++;

    }
    else{
      if(index == 0){
        cout<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
        cout << "                     thank god." << endl;
        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
        break;
      }
      index--;
    }
    cout << "Me trying to pass the semester";
    for(int i = 0; i<SIZE; i++){
      distance[i] = ".";
    }
    distance[index] = "X";
    for(int i = 0; i<SIZE; i++){
      delay(50);
      cout << distance[i] << " ";
    }
    cout << "Me procrastinating";
    cout << endl;
  }
}
