#include <iostream>
using namespace std;
#include "RegularPolygon.h"
#include "Square.h"
#include "Hexagon.h"

int main() {

	Square * square1 = new Square(6);
	cout <<"Length="<<square1 -> getLength()<<" Area="<<square1 ->getArea()<<endl;
	Hexagon * hexagon1 =new Hexagon(10);
	cout <<"Length="<<hexagon1 -> getLength()<<" Area="<<hexagon1 ->getArea()<<endl;

	RegularPolygon * polygon1 = new Square(7);  //polymorphism
	RegularPolygon * polygon2 = new Hexagon(7);  //polymorphism
	cout <<"Length="<<polygon1 -> getLength()<<" Area="<<polygon1 ->getArea()<<endl;
	cout <<"Length="<<polygon2 -> getLength()<<" Area="<<polygon2 ->getArea()<<endl;

	
	return 0;
}






