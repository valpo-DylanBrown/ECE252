#ifndef REGULAR_POLYGON_H
#define REGULAR_POLYGON_H  //prevent circular inclusions.

class RegularPolygon {

	protected:
		float sideLength;
		int numSides;
		
	public:
		RegularPolygon(); //Default constructor
		RegularPolygon(float length, int sides);
		
		float getLength(); 
		int getNumSides();
		void setLength(float length);
		void setNumSides(int sides);
		
		virtual float getArea()=0; 
								
		
};

#endif