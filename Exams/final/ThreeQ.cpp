#include<iostream>
using namespace std;
#define MAXSIZE 1000

class Queue{ //class for Queue, not needed but for my brain it helped

public:
  bool isEmpty(); //checks if q is empty
  bool isFull(); //checks if q is full
  int getSize(); //return size of q
  string dequeue(); //return and remove first string from q
  string getFirst(); //return first sttring from q
  void enqueue(string x); //add a new string to the end of the line
};

class ThreeQ{ //THREE Q's
private:
  Queue *q1; //q1
  Queue *q2; //q2
  Queue *q3; //q3
public:
  ThreeQ(); //constructor

  void enqueue(string x); //enqueue to smallest lie
  string dequeue1(); //remove first from line 1
  string dequeue2(); //remove first from line 2
  string dequeue3(); //remove first from line 3
  Queue *findMinQueue(); //interal function to return the smallest line
};

ThreeQ::ThreeQ(){
  Queue *q1 = new Queue(); //construct q
  Queue *q2 = new Queue(); //construct q
  Queue *q3 = new Queue(); //construct q
}

Queue* ThreeQ::findMinQueue(){
  int smallestNum; //variable for smallest size
  smallestNum = q1->getSize(); //set it to q1 to start
  if(q2->getSize() < smallestNum){ //is q2 smaller?
    smallestNum = q2->getSize(); //if so, set it
  }
  if(q3->getSize() < smallestNum){ //is q3 smaller?
    smallestNum = q3->getSize(); //if so, set it
  }
  //return the correct q
  if(smallestNum == q1->getSize())return q1;
  if(smallestNum == q2->getSize())return q2;
  if(smallestNum == q3->getSize())return q3;
}

void ThreeQ::enqueue(string x){ //enqueue function
  Queue* tmp = findMinQueue(); //tmp queue set to the smallest q found
  if(tmp->getSize() == MAXSIZE){ //if tmp is maxsize,all queues are MAXSIZE
    cout << "ALL QUEUES FULL" << endl; //output error
    return; //return
  }
  if(tmp->getSize()== q1->getSize() == q2->getSize() == q3->getSize()){
    //if all q's are tied
    q1->enqueue(x); //enqueue line 1
  }
  else if((tmp->getSize() == q1->getSize()) && (tmp->getSize() == q3->getSize())){
    //if q1 and q3 are tied
    q1->enqueue(x); //enqueue line 1
  }
  else if((tmp->getSize() == q2->getSize()) && (tmp->getSize() == q3->getSize())){
    //if q2 and q3 are tied
    q2->enqueue(x); //enqueue line 2
  }
  //no directions for q1 q2 tie
  else{ //if no ties
    tmp->enqueue(x); //enqueue whatever line tmp is AKA the min
  }
}

string ThreeQ::dequeue1(){
  if(q1->isEmpty()) //is line 1 empty?
    return "q1 empty"; //return a empty message
  else //otherwise
    return q1->dequeue(); //dequeue q1
}
string ThreeQ::dequeue2(){
  if(q2->isEmpty()) //is line 1 empty?
    return "q2 empty"; //return a empty message
  else //otherwise
    return q2->dequeue(); //dequeue q1
}
string ThreeQ::dequeue3(){
  if(q3->isEmpty()) //is line 1 empty?
    return "q3 empty"; //return a empty message
  else //otherwise
    return q3->dequeue(); //dequeue q1
}
