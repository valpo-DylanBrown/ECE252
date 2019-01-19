#include<iostream>
#include<math.h>

using namespace std;

class RightTriangle {

	private:
		float a;
		float b;
		float c;

	public:
		RightTriangle();
		RightTriangle(int x, int y, int hypotenuse);
    void printValues();
    bool isHypotenuseCorrect();
    void fixHypotenuse();
    void setHypotenuse(float x);
    float getHypotenuse();

};


int main () {
  RightTriangle* myTriangle = new RightTriangle(5, 12, 13);
  myTriangle->printValues();
  cout << "Hypotenuse correct? " << myTriangle->isHypotenuseCorrect() << endl;
  myTriangle->setHypotenuse(20);
  myTriangle->printValues();
  cout << "Hypotenuse correct? " << myTriangle->isHypotenuseCorrect() << endl;
  myTriangle->fixHypotenuse();
  myTriangle->printValues();
  cout << "Hypotenuse correct? " << myTriangle->isHypotenuseCorrect() << endl;
  cout << "Hypotenuse: " << myTriangle-> getHypotenuse() << endl;
	return 0;
}

RightTriangle::RightTriangle() {
	a = 3;
	b = 4;
	c = 5;
}

RightTriangle::RightTriangle(int x, int y, int hypotenuse) {
  a = x;
  b = y;
  c = hypotenuse;
}
bool RightTriangle::isHypotenuseCorrect(){
	if (fabs(a*a + b*b - c*c) < 0.0001){
		//cout << "1"<< endl;
		return true;
	} else {
		//cout << "0" << endl;
		return false;
	}
}

void RightTriangle::fixHypotenuse(){
	c=sqrt(a*a+b*b);
}

void RightTriangle::printValues(){
	cout << "side 1: " << a << ", side 2: " << b << ", hypotenuse: " << c << endl;
}
void RightTriangle::setHypotenuse(float x){
  c = x;
}
float RightTriangle:: getHypotenuse(){
  return c;
}
