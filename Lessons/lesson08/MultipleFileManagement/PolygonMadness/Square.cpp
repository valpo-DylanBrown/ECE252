#include <iostream>

using namespace std;
#include "RegularPolygon.h"
#include "Square.h"


Square::Square(){
	sideLength=1; 
	numSides=4;
}  //default constructor for square

Square::Square(float newLength){
	sideLength=newLength; 
	numSides=4;
}

float Square::getArea() {
	return sideLength*sideLength;
}
		




