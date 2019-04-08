#include <iostream>

using namespace std;

class Exam {

	private:
		int score;

	public:
		Exam() { score = 100; }
		Exam(float newScore) { score = newScore; }

		float getScore() { return score; }
		void print() { cout << "Score is: " << score << endl; }

};


int main() {
	Exam* p1;
	p1 = new Exam();
	p1->print();

	Exam* p2 = new Exam(77);
	p2->print();

	Exam e1;
	e1.print();

	Exam e2 = 75;
	e2.print();

	Exam e3(80);
	e3.print();
/*
	Exam oArray[3];
	oArray[0] = 93;
	oArray[1] = 90;
	oArray[2] = 11;
	for(int i = 0; i<3; i++){
		oArray[i].print();
	}
*/
	Exam* pArray[5];
	pArray[3] = new Exam(67);
 	pArray[3]->print();

}
