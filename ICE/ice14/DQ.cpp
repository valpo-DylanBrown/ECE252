#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAXSIZE 1000


class DEQArray {
private:
  int elements[MAXSIZE];
  int size;
  int start;
  int tail;
public:
  DEQArray(){
    size = 0;
    start =0;
    tail =0;
  };
  bool pushBack(int j);
  int popFront();
  int popBack();
  bool pushFront(int j);
  int getSize();
  bool isEmpty();
};
bool DEQArray::pushBack(int j){
  if(size == MAXSIZE){
    return false;
  }
  tail++;
  elements[tail] = j;
  size++;

  if(tail == MAXSIZE){
    tail = 0;
  }
  return true;
};
int DEQArray::popFront(){
  if(size == 0){
    return -1;
  }

  start++;
  if(start > MAXSIZE){
    start = start-MAXSIZE;
  }
  int val = elements[start];
  size--;
  return val;
};
int DEQArray::popBack(){
  if(size == 0){
    return -1;
  }
  //tail--;

  int val = elements[tail];
  tail--;
  if(tail < 0){
    tail = tail+MAXSIZE;
  }
  size--;
  return val;
};
bool DEQArray::pushFront(int j){
  if(size == MAXSIZE){
    return false;
  }
  elements[start] = j;
  start--;
  size++;

  if(start == 0){
    start = MAXSIZE;
  }
  return true;

};

int DEQArray::getSize(){
  return size;
};
bool DEQArray::isEmpty(){
  return size == 0;
};


int main(){
  DEQArray* myDEQ = new DEQArray();
  for(int i = 1; i<11; i++){
    //cout << "Added " << i <<": " << myDEQ->pushFront(i) <<endl;
    myDEQ->pushFront(i);
    //cout << "Added:" << i << endl;
  }
  for(int i = 10; i<=100; i+=10){
    //cout << "Added " << i <<": " << myDEQ->pushBack(i) <<endl;
    myDEQ->pushBack(i);
    //cout << "Added:" << i << endl;
  }

  for(int i = 0; i<15; i++){
    cout << "Front Pop: " << myDEQ->popFront() << endl;
  }

  for(int i = 0; i<10; i++){
    cout << "Back Pop: " << myDEQ->popBack() << endl;
  }
  return 0;

}

/*********************
======================
OUTPUT
======================
4c-32-75-9c-9c-29:ice14 dylan$ ./a.out
Front Pop: 10
Front Pop: 9
Front Pop: 8
Front Pop: 7
Front Pop: 6
Front Pop: 5
Front Pop: 4
Front Pop: 3
Front Pop: 2
Front Pop: 1
Front Pop: 10
Front Pop: 20
Front Pop: 30
Front Pop: 40
Front Pop: 50
Back Pop: 100
Back Pop: 90
Back Pop: 80
Back Pop: 70
Back Pop: 60
Back Pop: -1
Back Pop: -1
Back Pop: -1
Back Pop: -1
Back Pop: -1
*********************/
