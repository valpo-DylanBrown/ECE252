#include <iostream>

using namespace std;

class RegularPolygon {

	protected:
		float sideLength;
		int numSides;

	public:
		RegularPolygon() { sideLength = 1; numSides = 0; }

		RegularPolygon(float length, int sides) {
			sideLength = length;
			numSides = sides;
		}
		float getLength() { return sideLength; }
		int getNumSides() { return numSides; }
		void setLength(float length)  { sideLength = length; }
		void setNumSides(int sides) { numSides = sides; }

		virtual float getArea() = 0;
		//virtual float getArea() = 0;  //function will always be overridden by subclass.

};

class Square : public RegularPolygon {

	public:
		Square() { sideLength = 1; numSides = 4; }
		Square(int newLength) {
			sideLength = newLength;
			numSides = 4;
		}
		float getArea() { cout << "SQ ga \n"; return sideLength*sideLength; }

};

class Hexagon : public RegularPolygon {

	public:
		Hexagon() { sideLength = 1; numSides = 6; }
		Hexagon(int newLength) {
			sideLength = newLength;
			numSides = 6;
		}
		float getArea() {
		int x = getNumSides();
		return 2.598*sideLength*sideLength; }

};

int main() {

		//RegularPolygon* rp1 = new RegularPolygon();
		Square* sq1 = new Square(2);
		RegularPolygon* rp2 = new Square(8);
		//rp1 -> getArea();
		sq1->getArea();
		rp2->getArea();
		cout << "Get Sides: " << rp2->getNumSides() << endl;

	return 0;
}
