#include<iostream>
using namespace std;
class NumberPrinter{
protected:
  int digitOne, digitTwo, digitThree;
public:
  NumberPrinter();
  NumberPrinter(int firstDigit, int secondDigit, int thirdDigit);
  void setAllDigits(int x, int y, int z);
  void setFirstDigit(int x);
  void setSecondDigit(int x);
  void setThirdDigit(int x);

  virtual void print() = 0;
};

class SmallPrinter: public NumberPrinter{
public:
  SmallPrinter():NumberPrinter(){}
  SmallPrinter(int firstDigit, int secondDigit, int thirdDigit):NumberPrinter(firstDigit, secondDigit, thirdDigit){}

  void print();

};

class MediumPrinter: public NumberPrinter{
public:
  MediumPrinter():NumberPrinter(){}
  MediumPrinter(int firstDigit, int secondDigit, int thirdDigit):NumberPrinter(firstDigit, secondDigit, thirdDigit){}

  void print();

};

class LargePrinter: public NumberPrinter{
public:
  LargePrinter():NumberPrinter(){}
  LargePrinter(int firstDigit, int secondDigit, int thirdDigit):NumberPrinter(firstDigit, secondDigit, thirdDigit){}

  void print();
};
NumberPrinter::NumberPrinter(){
  digitOne = 0;
  digitTwo = 0;
  digitThree = 0;
}
NumberPrinter::NumberPrinter(int firstDigit, int secondDigit, int thirdDigit){
  digitOne = firstDigit;
  digitTwo = secondDigit;
  digitThree = thirdDigit;
}
void NumberPrinter::setFirstDigit(int x){
  digitOne = x;
}
void NumberPrinter::setSecondDigit(int x){
  digitTwo = x;
}
void NumberPrinter::setThirdDigit(int x){
  digitThree = x;
}
void NumberPrinter::setAllDigits(int x, int y, int z){
  setFirstDigit(x);
  setSecondDigit(y);
  setThirdDigit(z);
}

void SmallPrinter::print(){
  cout << digitOne << " " << digitTwo << " " << digitThree << endl;
  cout << endl << endl;
}
void MediumPrinter::print(){
  string ln1[10] = {" -- ", "    ", " -- ", " -- ", "    ", " -- ", " -- ", " -- ", " -- ", " -- "};
  string ln2[10] = {"|  |", "   |", "   |", "   |", "|  |", "|   ", "|   ", "   |", "|  |", "|  |"};
  string ln3[10] = {"|  |", "   |", "   |", "   |", "|  |", "|   ", "|   ", "   |", "|  |", "|  |"};
  string ln4[10] = {"    ", "    ", " -- ", " -- ", " -- ", " -- ", " -- ", "    ", " -- ", " -- "};
  string ln5[10] = {"|  |", "   |", "|   ", "   |", "   |", "   |", "|  |", "   |", "|  |", "   |"};
  string ln6[10] = {"|  |", "   |", "|   ", "   |", "   |", "   |", "|  |", "   |", "|  |", "   |"};
  string ln7[10] = {" -- ", "    ", " -- ", " -- ", "    ", " -- ", " -- ", "    ", " -- ", "    "};

  cout << ln1[digitOne] << " " << ln1[digitTwo] << " " << ln1[digitThree] << endl;
  cout << ln2[digitOne] << " " << ln2[digitTwo] << " " << ln2[digitThree] << endl;
  cout << ln3[digitOne] << " " << ln3[digitTwo] << " " << ln3[digitThree] << endl;
  cout << ln4[digitOne] << " " << ln4[digitTwo] << " " << ln4[digitThree] << endl;
  cout << ln5[digitOne] << " " << ln5[digitTwo] << " " << ln5[digitThree] << endl;
  cout << ln6[digitOne] << " " << ln6[digitTwo] << " " << ln6[digitThree] << endl;
  cout << ln7[digitOne] << " " << ln7[digitTwo] << " " << ln7[digitThree] << endl;
  cout << endl << endl;
}
void LargePrinter::print(){
  string ln1[10] = {" --- ", "     ", " --- ", " --- ", "     ", " --- ", " --- ", " --- ", " --- ", " --- "};
  string ln2[10] = {"|   |", "    |", "    |", "    |", "|   |", "|    ", "|    ", "    |", "|   |", "|   |"};
  string ln3[10] = {"|   |", "    |", "    |", "    |", "|   |", "|    ", "|    ", "    |", "|   |", "|   |"};
  string ln4[10] = {"|   |", "    |", "    |", "    |", "|   |", "|    ", "|    ", "    |", "|   |", "|   |"};
  string ln5[10] = {"     ", "     ", " --- ", " --- ", " --- ", " --- ", " --- ", "     ", " --- ", " --- "};
  string ln6[10] = {"|   |", "    |", "|    ", "    |", "    |", "    |", "|   |", "    |", "|   |", "    |"};
  string ln7[10] = {"|   |", "    |", "|    ", "    |", "    |", "    |", "|   |", "    |", "|   |", "    |"};
  string ln8[10] = {"|   |", "    |", "|    ", "    |", "    |", "    |", "|   |", "    |", "|   |", "    |"};
  string ln9[10] = {" --- ", "     ", " --- ", " --- ", "     ", " --- ", " --- ", "     ", " --- ", "     "};

  cout << ln1[digitOne] << " " << ln1[digitTwo] << " " << ln1[digitThree] << endl;
  cout << ln2[digitOne] << " " << ln2[digitTwo] << " " << ln2[digitThree] << endl;
  cout << ln3[digitOne] << " " << ln3[digitTwo] << " " << ln3[digitThree] << endl;
  cout << ln4[digitOne] << " " << ln4[digitTwo] << " " << ln4[digitThree] << endl;
  cout << ln5[digitOne] << " " << ln5[digitTwo] << " " << ln5[digitThree] << endl;
  cout << ln6[digitOne] << " " << ln6[digitTwo] << " " << ln6[digitThree] << endl;
  cout << ln7[digitOne] << " " << ln7[digitTwo] << " " << ln7[digitThree] << endl;
  cout << ln8[digitOne] << " " << ln8[digitTwo] << " " << ln8[digitThree] << endl;
  cout << ln9[digitOne] << " " << ln9[digitTwo] << " " << ln9[digitThree] << endl;
  cout << endl << endl;
}
int main(){
  MediumPrinter* medPrint = new MediumPrinter();
  medPrint->print();
  SmallPrinter* smallPrint = new SmallPrinter(5,7,9);
  LargePrinter* lgPrint = new LargePrinter(5,7,9);
  smallPrint->print();
  lgPrint->print();
  lgPrint->setAllDigits(4,7,8);
  lgPrint->print();
  NumberPrinter* printArr[8];
  printArr[0] = new SmallPrinter(0,1,2);
  printArr[1] = new SmallPrinter(3,4,5);
  printArr[2] = new SmallPrinter(6,7,8);
  printArr[3] = new MediumPrinter(0,1,2);
  printArr[4] = new MediumPrinter(3,4,5);
  printArr[5] = new MediumPrinter(6,7,8);
  printArr[6] = new LargePrinter(0,1,2);
  printArr[7] = new LargePrinter(3,4,5);
  printArr[8] = new LargePrinter(6,7,8);
  for(int i=0; i<9;i++){
    printArr[i]->print();
  }
  return 0;
}
