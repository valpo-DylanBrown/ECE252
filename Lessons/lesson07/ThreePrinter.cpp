#include <iostream>
using namespace std;

#define NUM_CHARS 3

class ThreePrinter {

	private:

	public:
	  void print(int x, int y);
	  void printA(int x, int y);

};


void ThreePrinter::print(int x, int y) {
	//first line
	if(x==0){
		cout <<"---";
	}
	if(x==1){
		cout << "| |";
	}
	if(x==2){
		cout << "X X";
	}
	cout << " ";
	if(y==0){
		cout <<"---";
	}
	if(y==1){
		cout << "| |";
	}
	if(y==2){
		cout << "X X";
	}
	cout << endl;
	//second line
	if(x==0){
		cout <<"| |";
	}
	if(x==1){
		cout << "|-|";
	}
	if(x==2){
		cout << " X ";
	}
	cout << " ";
	if(y==0){
		cout <<"| |";
	}
	if(y==1){
		cout << "|-|";
	}
	if(y==2){
		cout << " X ";
	}
	cout << endl;
	//third line
	if(x==0){
		cout <<"---";
	}
	if(x==1){
		cout << "| |";
	}
	if(x==2){
		cout << "X X";
	}
	cout << " ";
	if(y==0){
		cout <<"---";
	}
	if(y==1){
		cout << "| |";
	}
	if(y==2){
		cout << "X X";
	}
	cout << endl;
}

void ThreePrinter::printA( int x, int y) {
	string line1[3] = {"---", "| |", "X X"};
	string line2[3] = {"| |", "|-|", " X "};
	string line3[3] = {"---", "| |", "X X"};

	cout << line1[x] << " " << line1[y] << endl;
	cout << line2[x] << " " << line2[y] << endl;
	cout << line3[x] << " " << line3[y] << endl;
	cout <<endl << endl;
}

int main() {

	ThreePrinter* myThree = new ThreePrinter();

	myThree->printA(1,2);
	//myThree.print(0, 1);

	myThree->printA(0,1);
	myThree->printA(2,1);

	return 0;
}
