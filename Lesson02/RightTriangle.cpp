#include<iostream>
#include<math.h>
using namespace std;

class RightTriangle{

	private:
		int a;
		int b;
		int c;

	public:
		RightTriangle();  //default constructor
		RightTriangle(int x, int y, int hypotenuse); //non-default constructor

		void printValues();
		bool isHypotenuseCorrect();
		void fixHypotenuse();

		bool setA(int x);
		bool setB(int y);
		bool setC(int hypotenuse);

};

int main () {


}

RightTriangle::RightTriangle(){

}

RightTriangle::RightTriangle(int x, int y, int hypotenuse){

}

void RightTriangle::printValues(){
	cout << a << endl << b << endl << c << endl;
}

bool RightTriangle::isHypotenuseCorrect(){
	if (fabs(a*a + b*b - c*c) < 0.0001){
		cout << "YES!"<< endl;
		return true;
	} else {
		cout << "NO!" << endl;
		return false;
	}
}

void RightTriangle::fixHypotenuse(){
	c=sqrt(a*a+b*b);
}

bool RightTriangle:: setA (int x){

}

bool RightTriangle:: setB (int y){

}

bool RightTriangle:: setC (int hypotenuse){

}
