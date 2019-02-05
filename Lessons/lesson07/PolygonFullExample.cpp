#include <iostream>
using namespace std;

class RegularPolygon {
	protected: //will be inherited by derived classes.
		float sideLength;
		int numSides;
	public:
		RegularPolygon() {sideLength=1; numSides=0;}
		RegularPolygon(float newLength, int newSides){
			sideLength=newLength; numSides=newSides;
		}
		
		float getLength() {return sideLength;}  //getters
		int getnumSides() {return numSides;}
		void setLength(float newLength) {sideLength=newLength;}  //setters
		void setNumSides(int newSides) {numSides=newSides;}
		
		virtual float getArea()=0;  
		//virtual means it is intended to be overwritten by the child.
		//Can never actually declare a polygon object.
		//Can only inherit from a polygon.
		
		void regularFunction(){ cout << "Polygon's Regular Function." << endl;}
		virtual void virtualFunction(){ cout << "Polygon's Virtual Function." << endl;}
};

class Square : public RegularPolygon { //Square inherits all protected and public features of RegularPolygon

	public:
		Square() { sideLength=1; numSides=4;}  //default constructor for a square.
		Square(float newLength) {sideLength=newLength; numSides=4;}
		float getArea() {return sideLength*sideLength;}
		//This overrides the getArea function derived from Regular Polygon.
		void regularFunction() {cout << "Square's regular function."<< endl;}
		virtual void virtualFunction() {cout << "Square's virtual function."<< endl;}
		
};


class Hexagon : public RegularPolygon { 
	public:
		Hexagon() {sideLength=1; numSides=6;}  //default constructor for a hexagon.
		Hexagon(float newLength) {sideLength=newLength; numSides=6;}
		float getArea() {return 2.598*sideLength*sideLength;}
};

int main() {
	//RegularPolygon * regpoly1 = new RegularPolygon();
	Square * square1 = new Square(6);
	cout << "Length=" << square1 -> getLength() << endl;
	cout << "Area=" << square1 -> getArea() << endl;
	Hexagon * hexagon1 = new Hexagon(10);
	cout << "Length=" << hexagon1 -> getLength() << endl;
	cout << "Area=" << hexagon1 -> getArea() << endl;

	
	
	//Polymorphism:
	RegularPolygon * polygon1 = new Square(7);
	cout << "Length=" << polygon1 -> getLength() << endl;
	cout << "Area=" << polygon1 -> getArea() << endl;
	RegularPolygon * polygon2 = new Hexagon(15);
	cout << "Length=" << polygon2 -> getLength() << endl;
	cout << "Area=" << polygon2 -> getArea() << endl;
	
	//Virtual functions:
	square1 -> regularFunction();
	square1 -> virtualFunction();
	hexagon1 -> virtualFunction();
	polygon1 -> regularFunction();
	polygon1 -> virtualFunction();

	return 0;
}


















