/*---------------------------------------------------------
Dylan Brown
ECE252
Individual Assignment 1

I have neither given or recieved, nor have I tolerated others' use
of unauthorized aid.


---------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class AllKinds{
private:
  int x;
  long y;
  float z;
public:
  AllKinds();
  AllKinds(int a, long b, float c);
  long intPlusLong();
  float intPlusFloat();
  float longMinusFloat();
  int getInt();
  void setInt(int a);
  long getLong();
  void setLong(long b);
  float getFloat();
  void setFloat(float c);
  void printValues();
};
int main(){
<<<<<<< HEAD
  AllKinds* setOne = new AllKinds(5, 12345, 19.2);
=======
  AllKinds* setOne = new AllKinds(5, 12635, 19.2);
>>>>>>> 279814ade975af4195740cf049dc5516d51ea441
  AllKinds* setTwo = new AllKinds();
  setOne->printValues();
  setTwo->printValues();
  setTwo->setInt(7);
  setTwo->setFloat(1124.65);
  setTwo->setLong(11265);
  setTwo->printValues();
<<<<<<< HEAD
  cout << "-------------------FUNCTIONS w Default-------------------" << endl;
  cout << "Integer + Long = " << setTwo->intPlusLong() << endl;
  cout << "Integer + Float = " << setTwo->intPlusFloat() << endl;
  cout << "Long - Float = " << setTwo->longMinusFloat() << endl;
  cout << "-----------------FUNCTIONS w Initial Case-----------------" << endl;
  cout << "Integer + Long = " << setOne->intPlusLong() << endl;
  cout << "Integer + Float = " << setOne->intPlusFloat() << endl;
  cout << "Long - Float = " << setOne->longMinusFloat() << endl;
=======
  cout << "-------------------FUNCTIONS W/ DEFAULT-------------------" << endl;
  cout << "Integer + Long = " << setTwo->intPlusLong() << endl;
  cout << "Integer + Float = " << setTwo->intPlusFloat() << endl;
  cout << "Long - Float = " << setTwo ->longMinusFloat() << endl;
  cout << "-------------------FUNCTIONS W/ INTITALIZER-------------------" << endl;
  cout << "Integer + Long = " << setOne->intPlusLong() << endl;
  cout << "Integer + Float = " << setOne->intPlusFloat() << endl;
  cout << "Long - Float = " << setOne ->longMinusFloat() << endl;
>>>>>>> 279814ade975af4195740cf049dc5516d51ea441
}
AllKinds::AllKinds(){
  //default values
  x = -1;
  y = -1;
  z = -1;
}
AllKinds::AllKinds(int a, long b, float c){
  x = a;
  y = b;
  z = c;
}
void AllKinds:: printValues(){
  cout << "Set: " << endl;
  cout << getInt() << ", " << getLong() << ", " << getFloat() << endl;
}
long AllKinds::intPlusLong(){
  return x+y;
}
float AllKinds::intPlusFloat(){
  return x+z;
}
float AllKinds::longMinusFloat(){
  return y-z;
}
int AllKinds::getInt(){
  return x;
}
void AllKinds::setInt(int a){
  x = a;
}
long AllKinds::getLong(){
  return y;
}
void AllKinds::setLong(long b){
  y = b;
}
float AllKinds::getFloat(){
  return z;
}
void AllKinds::setFloat(float c){
  z = c;
}
