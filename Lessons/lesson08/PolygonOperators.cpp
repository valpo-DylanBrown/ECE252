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
		virtual float getArea() = 0;
		float getLength() { return sideLength; }
		int getNumSides() { return numSides; }
		void setLength(float length)  { sideLength = length; }
		void setNumSides(int sides) { numSides = sides; }

		bool operator== (RegularPolygon& other){
			if(sideLength == other.getLength()){
				return true;
			}
			else{
				return false;
			}
		}
};

class Square : public RegularPolygon {

	public:
		Square() { sideLength = 1; numSides = 4; }
		Square(int newLength) {
			sideLength = newLength;
			numSides = 4;
		}
		float getArea() { return sideLength*sideLength; }

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

	Square* square1 = new Square(6);
	cout << "Length=" << square1->getLength() << " Area=" << square1->getArea() << endl;

	RegularPolygon* poly1 = new Square(12);
	cout << "Length=" << poly1->getLength() << " Area=" << poly1->getArea() << endl;

	if(*square1 == *poly1) cout << "Equal!" << endl;
	else cout << "False!" << endl;
	return 0;
}
