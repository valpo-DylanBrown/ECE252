#ifndef SQUARE_H
#define SQUARE_H  //prevent circular inclusions.

class Square : public RegularPolygon { 

	public:
		Square(); 
		Square(float newLength);
		float getArea();
};

#endif