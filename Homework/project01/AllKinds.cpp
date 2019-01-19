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
  void setInt();
  long getLong();
  void setLong();
  float getFloat();
  void setFloat();
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
