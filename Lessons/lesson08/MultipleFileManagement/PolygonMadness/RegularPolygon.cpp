#include <iostream>
using namespace std;
#include "RegularPolygon.h"


RegularPolygon::RegularPolygon(){
	sideLength=1; 
	numSides=0;
}  //Default constructor

RegularPolygon::RegularPolygon(float length, int sides){  //Initializing constructor
	sideLength=length; 
	numSides=sides;
}
		
float RegularPolygon::getLength() { 
	return sideLength;
}  //getters

int RegularPolygon::getNumSides() {
	return numSides;
}
void RegularPolygon::setLength(float length) {
	sideLength=length;
} //setter

void RegularPolygon::setNumSides(int sides) {
	numSides=sides;
}

		


