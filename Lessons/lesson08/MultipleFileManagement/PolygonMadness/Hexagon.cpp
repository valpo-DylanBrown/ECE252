#include "RegularPolygon.h"
#include "Hexagon.h"

Hexagon::Hexagon(){
	sideLength=1; 
	numSides=6;
}  

Hexagon::Hexagon(float newLength){
	sideLength=newLength; 
	numSides=6;
}

float Hexagon::getArea() {
	return 2.598*sideLength*sideLength;
}
	


