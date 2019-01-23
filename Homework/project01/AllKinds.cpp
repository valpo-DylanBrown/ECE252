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
  AllKinds* setOne = new AllKinds(5, 1334029776, 19.2);
  AllKinds* setTwo = new AllKinds();
  setOne->printValues();
  setTwo->printValues();
  cout << "Integer + Long " << setOne->intPlusLong() << endl;
  cout << "Integer + Float " << setOne->intPlusFloat() << endl;
  setOne->setInt(7);
  setOne->setFloat(2000.198);
  setOne->setLong(200000);
  setOne->printValues();
  cout << "Long - Float " << setOne->longMinusFloat() << endl;
}
AllKinds::AllKinds(){
  //default values
  x = 12;
  y = 192837749019;
  z = 23.45;
}
AllKinds::AllKinds(int a, long b, float c){
  //default values
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
