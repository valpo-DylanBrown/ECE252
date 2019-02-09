#ifndef HEXAGON_H
#define HEXAGON_H  //prevent circular inclusions.

class Hexagon : public RegularPolygon { 

	public:
		Hexagon(); 
		Hexagon(float newLength);
		float getArea();
};

#endif