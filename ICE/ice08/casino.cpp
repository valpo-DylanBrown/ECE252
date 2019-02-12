#include <iostream>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_GAMES 1
#define NUMPIECES 6
using namespace std;

class OhRats {
	private:
		int puzzle[NUMPIECES];
		int pieces;

	public:
		OhRats() {initial();} //Default of two players
		void initial();
		void addPiece();
		//bool checkPiece();
		bool checkWin();
		int spin();
};

void OhRats::initial() {
	for(int i=0; i<=NUMPIECES; i++) {
		puzzle[i]=0;
	}
	pieces=0;
}

void OhRats::addPiece() {
	int current=spin();
	if(puzzle[current]==0)
	{
		puzzle[current]=1;
		pieces++;
	}
}

bool OhRats::checkWin() {
	if(pieces==NUMPIECES){
		return true;
	}
	else return false;
}

int OhRats::spin() {
	//srand(time(NULL));
	return rand() %6 + 1;
}
/* -------------------------
PROBLEM 1
------------------------- */
int main(){
srand(time(NULL));
int dealerWinCount = 0;
int dealerTotal = 0;
cout << "Welcome" << endl;
  for(int i=0; i<NUM_GAMES;i++){ //100,000 games
    OhRats dealer; // reinst every game
    OhRats player1; // reinst every game
    while(1){ //until a winner
      if(dealer.checkWin()){
        dealerWinCount++;
        dealerTotal++;
				cout << "D winner" << endl;
        break;
      }
      else if(player1.checkWin()){
        dealerTotal--;
				cout << "P winner" << endl;
        break;

      }
      else{
				cout << "No Winners" << endl;
        dealer.spin();
        dealer.addPiece();
        player1.spin();
        player1.addPiece();
      }
    } // end while

  }
cout << "Dealer Win Count: " << dealerWinCount << endl;
cout << "Dealer Total: " << dealerTotal << endl;


}

/* -------------------------
PROBLEM 2
------------------------- */
/*
int main(){

int turnCountTotal = 0;

  for(int i=0; i<NUM_GAMES;i++){ //100,000 games
    OhRats player[3];
    int turnCount = 0;
    while(1){ //until a winner
      if(player[0].checkWin() || player[1].checkWin() || player[2].checkWin() || player[3].checkWin()){
        break;
      }
      else{
        for(int j=0; j<4; j++){
          player[j].spin();
          player[j].addPiece();
          turnCountTotal++;
        }
      }
    } // end while

  }
cout << "Average Turns: " << turnCountTotal/NUM_GAMES << endl;
}*/
