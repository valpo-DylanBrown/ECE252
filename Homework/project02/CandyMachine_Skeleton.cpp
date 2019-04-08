#include <iostream>
#include <stdio.h>
using namespace std;

//*******************************
//NEED TO TEST MORE
//*******************************

float newRand();

class CandyMachine {

	private:
		//member variables go here.  All variables must be private.
		int itemA = 5;
		const int costA = 75;
		int itemB = 3;
		const int costB = 90;
		int itemC = 5;
		const int costC = 125;
		int moneyEntered;
		float storedMoney;
	public:
		CandyMachine();

		// returns the value of the money in the machine in dollars as a float, such as
		// 10.75 to represent ten dollars and 75 cents.
		float getAmountStoredMoney();

		// allows the user to add in money, in cents.
		// to add a quarter, call addMoney(25);
		void addMoney(unsigned int cents);

		// each of these functions represents pushing the respective button.
		// The user must have entered in sufficient money for the item.
		// Prints out a message indicating success of purchase and the change the user receives
		void pressAButton();
		void pressBButton();
		void pressCButton();

		// prints out a message indicating the cost of each item in cents
		void showCostA();
		void showCostB();
		void showCostC();

		// returns the value of the number of each item.  Does not print to screen.
		int getAsRemaining();
		int getBsRemaining();
		int getCsRemaining();

		// prints out a message indicating how much money, in cents, the user has entered.
		void showMoneyEntered();

		//A = Snickers = $0.75 = 5 to start
		//B = Cookies = $0.90 = 3 to start
		//C = Soda = $1.25 = 5 to start

};
//************************************
//private functions
//************************************
CandyMachine::CandyMachine(){
	int moneyEntered = 0;
	float storedMoney = 0.0;
}

float CandyMachine::getAmountStoredMoney(){
	return storedMoney *0.01;
}
void CandyMachine::showMoneyEntered(){
	cout << "You have entered " << moneyEntered << " cents." << endl;
}


void CandyMachine::addMoney(unsigned int cents){
	moneyEntered += cents;
}


void CandyMachine::pressAButton(){
	if(itemA != 0){ //is the item in stock?
		if (moneyEntered < costA){ //not enough money
			cout << "You need to add an additional " << costA - moneyEntered;
			cout << " cents." << endl;
		}
		else if (moneyEntered > costA){ //too much money
			cout << "Wise Choice. Recieve Item A";
			cout << " and your " << moneyEntered - costA << " cents change below.";
			cout << endl;
			storedMoney+=costA;
			moneyEntered = 0;
			itemA--;
		}
		else{//if the same amount
			cout << "Wise Choice. Recieve Item A below." << endl;
			storedMoney+=costA;
			moneyEntered = 0;
			itemA--;
		}
	}
	else{ //not in stock
		cout << "Sorry, that item is out. Please choose another." << endl;
	}
}
void CandyMachine::pressBButton(){
	if(itemB != 0){//is the item in stock?
		if (moneyEntered < costB){//not enough money
			cout << "You need to add an additional " << costB - moneyEntered;
			cout << " cents." << endl;
		}
		else if (moneyEntered > costB){//too much money
			cout << "Wise Choice. Recieve Item B";
			cout << " and your " << moneyEntered - costB << " cents change below.";
			cout << endl;
			storedMoney+=costB;
			moneyEntered = 0;
			itemB--;
		}
		else{//if the same amount
			cout << "Wise Choice. Recieve Item B below." << endl;
			storedMoney+=costB;
			moneyEntered = 0;
			itemB--;
		}
	}
	else{//not in stock
		cout << "Sorry, that item is out. Please choose another." << endl;
	}
}
void CandyMachine::pressCButton(){
	if(itemC != 0){//is the item in stock?
		if (moneyEntered < costC){//not enough money
			cout << "You need to add an additional " << costC - moneyEntered;
			cout << " cents." << endl;
		}
		else if (moneyEntered > costC){//too much money
			cout << "Wise Choice. Recieve Item C";
			cout << " and your " << moneyEntered - costC << " cents change below.";
			storedMoney+=costC;
			cout << endl;
			moneyEntered = 0;
			itemC--;
		}
		else{//if the same amount
			cout << "Wise Choice. Recieve Item C below." << endl;
			storedMoney+=costC;
			moneyEntered = 0;
			itemC--;
		}
	}
	else{//not in stock
		cout << "Sorry, that item is out. Please choose another." << endl;
	}
}



void CandyMachine::showCostA(){
	cout << "Item A costs " << costA << " cents." << endl;
}
void CandyMachine::showCostB(){
	cout << "Item B costs " << costB << " cents." << endl;
}
void CandyMachine::showCostC(){
	cout << "Item C costs " << costC << " cents." << endl;
}
int CandyMachine::getAsRemaining(){
	return itemA;
}
int CandyMachine::getBsRemaining(){
	return itemB;
}
int CandyMachine::getCsRemaining(){
	return itemC;
}
//************************************
//simple Main from the handout example
//output should match handout character by character
//************************************
/*
int main() {

	CandyMachine* machine = new CandyMachine();

	machine->addMoney(25);
	machine->addMoney(10);
	machine->addMoney(25);
	machine->showMoneyEntered();
	machine->addMoney(50);
	machine->pressAButton();
	machine->showCostA();

	printf("Machine contains $%.2f.\n", machine->getAmountStoredMoney());

	machine->addMoney(50);
	machine->pressAButton();
	machine->addMoney(105);
	machine->pressAButton();
	machine->pressAButton();
	machine->pressAButton();
	machine->addMoney(125);
	machine->pressBButton();

	printf("Machine contains $%.2f.\n", machine->getAmountStoredMoney());
	cout << "There are " << machine->getAsRemaining() << " A's left." << endl;

	machine->addMoney(75);
	machine->pressAButton();

	cout << "There are " << machine->getAsRemaining() << " A's left." << endl;

	machine->addMoney(85);
	machine->pressAButton();

	machine->addMoney(90);
	machine->pressAButton();

	machine->addMoney(95);
	machine->pressAButton();
	machine->pressBButton();

}
*/
//*************************
// Use THIS main() in order to comprehensively test
// your class.  Include its output in your solution
//*************************

int main() {

	CandyMachine* machine1 = new CandyMachine();
	CandyMachine* machine2 = new CandyMachine();
	CandyMachine* machine3 = new CandyMachine();

	for (int i=0; i<8; i++) {
		machine1->addMoney(newRand()*150);
		machine2->addMoney(newRand()*100);
		machine3->addMoney(newRand()*50);
		machine3->addMoney(newRand()*50);

		machine1->showMoneyEntered();
		machine2->showMoneyEntered();
		machine3->showMoneyEntered();

		machine1->pressAButton();
		machine2->pressBButton();
		machine3->pressCButton();
		cout << endl;
	}

	machine1->addMoney(200);
	machine2->addMoney(200);
	machine3->addMoney(200);

	machine1->showMoneyEntered();
	machine2->showMoneyEntered();
	machine3->showMoneyEntered();
	cout << endl;

	machine1->pressCButton();
	machine2->pressAButton();
	machine3->pressBButton();

	machine1->addMoney(90);
	machine2->addMoney(75);
	machine3->addMoney(125);

	machine1->pressBButton();
	machine2->pressAButton();
	machine3->pressCButton();


	printf("\nMachine 1 contains $%.2f\n", machine1->getAmountStoredMoney());
	cout << "There are " << machine1->getAsRemaining() << " A's left in Machine 1." << endl;

	printf("Machine 2 contains $%.2f\n", machine2->getAmountStoredMoney());
	cout << "There are " << machine2->getCsRemaining() << " C's left in Machine 2." << endl;

	printf("Machine 3 contains $%.2f\n", machine3->getAmountStoredMoney());
	cout << "There are " << machine3->getCsRemaining() << " C's left in Machine 3." << endl << endl;

	for (int i=0; i<5; i++) {
		machine1->addMoney(newRand()*50);
		machine2->addMoney(newRand()*200);
		machine1->addMoney(newRand()*150);
		machine3->addMoney(newRand()*50);
		machine1->pressBButton();
		machine2->pressCButton();
		machine3->pressCButton();
		cout << endl;
	}

	machine1->showCostA();
	machine2->showCostB();
	machine3->showCostC();
	cout << endl;


	cout << endl << "final tally: " << endl;
	cout << "Machine 1:" << endl;
	printf("%d\t%d\t%d\t%.2f\n", machine1->getAsRemaining(),machine1->getBsRemaining(),machine1->getCsRemaining(),machine1->getAmountStoredMoney());

	cout << "Machine 2:" << endl;
	printf("%d\t%d\t%d\t%.2f\n", machine2->getAsRemaining(),machine2->getBsRemaining(),machine2->getCsRemaining(),machine2->getAmountStoredMoney());

	cout << "Machine 3:" << endl;
	printf("%d\t%d\t%d\t%.2f\n\n", machine3->getAsRemaining(),machine3->getBsRemaining(),machine3->getCsRemaining(),machine3->getAmountStoredMoney());



}
float newRand()
  {
    static unsigned short lfsr = 0xACE1u;
	unsigned bit;

    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    lfsr = (  (lfsr >> 1) | (bit << 15));
	return (float)lfsr/65536;
  }


//*************************
// SIMPLE OUTPUT
//*************************
/*
$ a.exe
You have entered 60 cents.
Wise Choice. Recieve Item A and your 35 cents change below.
Item A costs 75 cents.
Machine contains $0.75.
You need to add an additional 25 cents.
Wise Choice. Recieve Item A and your 80 cents change below.
You need to add an additional 75 cents.
You need to add an additional 75 cents.
Wise Choice. Recieve Item B and your 35 cents change below.
Machine contains $2.40.
There are 3 A's left.
Wise Choice. Recieve Item A below.
There are 2 A's left.
Wise Choice. Recieve Item A and your 10 cents change below.
Wise Choice. Recieve Item A and your 15 cents change below.
Sorry, that item is out. Please choose another.
Wise Choice. Recieve Item B and your 5 cents change below.
*/
//*************************
// COMPREHENSIVE OUTPUT
//*************************
/*
$ a.exe
You have entered 50 cents.
You have entered 66 cents.
You have entered 16020940 cents.
You need to add an additional 25 cents.
You need to add an additional 24 cents.
Wise Choice. Recieve Item C and your 16020815 cents change below.

You have entered 62 cents.
You have entered 120 cents.
You have entered 19 cents.
You need to add an additional 13 cents.
Wise Choice. Recieve Item B and your 30 cents change below.
You need to add an additional 106 cents.

You have entered 147 cents.
You have entered 78 cents.
You have entered 85 cents.
Wise Choice. Recieve Item A and your 72 cents change below.
You need to add an additional 12 cents.
You need to add an additional 40 cents.

You have entered 33 cents.
You have entered 89 cents.
You have entered 125 cents.
You need to add an additional 42 cents.
You need to add an additional 1 cents.
Wise Choice. Recieve Item C below.

You have entered 128 cents.
You have entered 170 cents.
You have entered 67 cents.
Wise Choice. Recieve Item A and your 53 cents change below.
Wise Choice. Recieve Item B and your 80 cents change below.
You need to add an additional 58 cents.

You have entered 109 cents.
You have entered 86 cents.
You have entered 98 cents.
Wise Choice. Recieve Item A and your 34 cents change below.
You need to add an additional 4 cents.
You need to add an additional 27 cents.

You have entered 16 cents.
You have entered 91 cents.
You have entered 137 cents.
You need to add an additional 59 cents.
Wise Choice. Recieve Item B and your 1 cents change below.
Wise Choice. Recieve Item C and your 12 cents change below.

You have entered 35 cents.
You have entered 6 cents.
You have entered 64 cents.
You need to add an additional 40 cents.
Sorry, that item is out. Please choose another.
You need to add an additional 61 cents.

You have entered 235 cents.
You have entered 206 cents.
You have entered 264 cents.

Wise Choice. Recieve Item C and your 110 cents change below.
Wise Choice. Recieve Item A and your 131 cents change below.
Wise Choice. Recieve Item B and your 174 cents change below.
Wise Choice. Recieve Item B below.
Wise Choice. Recieve Item A below.
Wise Choice. Recieve Item C below.

Machine 1 contains $4.40
There are 2 A's left in Machine 1.
Machine 2 contains $4.20
There are 5 C's left in Machine 2.
Machine 3 contains $5.90
There are 1 C's left in Machine 3.

Wise Choice. Recieve Item B and your 62 cents change below.
You need to add an additional 37 cents.
You need to add an additional 82 cents.

You need to add an additional 10 cents.
Wise Choice. Recieve Item C and your 56 cents change below.
You need to add an additional 52 cents.

Wise Choice. Recieve Item B and your 97 cents change below.
Wise Choice. Recieve Item C and your 55 cents change below.
You need to add an additional 41 cents.

Sorry, that item is out. Please choose another.
You need to add an additional 14 cents.
Wise Choice. Recieve Item C and your 3 cents change below.

Sorry, that item is out. Please choose another.
Wise Choice. Recieve Item C and your 80 cents change below.
Sorry, that item is out. Please choose another.

Item A costs 75 cents.
Item B costs 90 cents.
Item C costs 125 cents.


final tally:
Machine 1:
2       0       4       6.20
Machine 2:
3       0       2       7.95
Machine 3:
5       2       0       7.15
*/
