#include <iostream>
using namespace std;

class RegularPolygon {
	protected: //will be inherited by derived classes.
		float sideLength;
		int numSides;
	public:
		RegularPolygon() {}
		RegularPolygon(float newLength, int newSides){
			sideLength=newLength; numSides=newSides;
		}
		//virtual float getArea(){cout << "\nRP's Function\n"; return -1928387; }
		virtual float getArea() = 0;
		float getLength() {return sideLength;}  //getters
		int getnumSides() {return numSides;}
		void setLength(float newLength) {sideLength=newLength;}  //setters
		void setNumSides(int newSides) {numSides=newSides;}

};

class Square : public RegularPolygon { //Square inherits all protected and public features of RegularPolygon

	public:
		Square() { numSides = 4; }  //default constructor for a square.
		Square(float newLength) {
			numSides = 4;
			sideLength = newLength;
		}
		float getArea() {return sideLength*sideLength;}
		//This getArea overrides the getArea function derived from Regular Polygon.

};


class Hexagon : public RegularPolygon {
	public:
		Hexagon() {numSides = 6;}  //default constructor for a hexagon.
		Hexagon(float newLength) {numSides = 6; sideLength = newLength;}
		float getArea() {return 2.598*sideLength*sideLength;}

};

int main() {
	RegularPolygon * regpoly1 = new RegularPolygon();
	cout << regpoly1->getnumSides() << endl;
	//cout << regpoly1->getArea() << endl;

	Square * square1 = new Square(6);
	cout << "Length=" << square1 -> getLength() << endl;
	cout << "Area=" << square1 -> getArea() << endl;

	Hexagon * hexagon1 = new Hexagon(6);
	cout << "Length=" << hexagon1 -> getLength() << endl;
	cout << "Area=" << hexagon1 -> getArea() << endl;

	RegularPolygon * poly1 = new RegularPolygon();
	RegularPolygon * poly2 = new Square(9);
	RegularPolygon * poly3 = new Hexagon(11);
	cout << "Area=" << poly1 -> getArea() << endl;
	cout << "Area=" << poly2 -> getArea() << endl;
	cout << "Area=" << poly3 -> getArea() << endl;



	return 0;
}


//super::f1();
