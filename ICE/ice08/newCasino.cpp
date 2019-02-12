#include <iostream>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_GAMES 100000 //number of games being played
#define NUM_PIECES 6 // number of game pieces
#define NUM_PLAYERS 4
#define PLAYTIME 5
using namespace std;

class OhRats {
	private:
		int puzzle[NUM_PIECES]; // //symbolizes pieces for players
		int pieces; //running total of piece count

	public:
		OhRats() {initial();}
		void initial(); //intializes array
		void addPiece(); //adds piece (also checks if piece is present)
		//bool checkPiece();
		bool checkWin(); //checks for win
		int spin(); //spins random int 0-5
};

void OhRats::initial() {
	for(int i=0; i<NUM_PIECES; i++) { //fills array with zeros to indicate no piece
		puzzle[i]=0;
	}
	pieces=0;
}

void OhRats::addPiece() {
	int current=spin(); //random num
	if(puzzle[current]==0) //if it is zero, replace it
	{
		puzzle[current]=1;
		pieces++;
	} //else do nothing
}

bool OhRats::checkWin() {
	if(pieces==NUM_PIECES){
		return true;
	}
	else return false;
}

int OhRats::spin() {
	return rand() %6;
}
/* -------------------------
PROBLEM 1
------------------------- */
/*int main(){
srand(time(NULL));
int dealerWinCount = 0;
int dealerTotal = 0;
  for(int i=0; i<NUM_GAMES;i++){ //NUMBER OF GAMES PLAYED
    OhRats dealer; // reinst every game
    OhRats player1; // reinst every game
    while(1){ //until a winner
      if(dealer.checkWin()){
        dealerWinCount++;
        dealerTotal++;
				//cout << "D winner" << endl;
        break;
      }
      else if(player1.checkWin()){
        dealerTotal--;
				//cout << "P winner" << endl;
        break;

      }
      else{
				//no winners
        dealer.spin();
        dealer.addPiece();
        player1.spin();
        player1.addPiece();
      }
    } // end while

  }
cout << "Dealer Win Count: " << dealerWinCount << endl;
cout << "Dealer Total: " << dealerTotal << endl;


}*/

/* -------------------------
PROBLEM 2
------------------------- */

int main(){
srand(time(NULL));
int turnCountTotal = 0;
float average;
  for(int i=0; i<NUM_GAMES;i++){ //number of games played
    OhRats player[NUM_PLAYERS-1]; //amount of players (0 counts as a player)
    int turnCount = 0; //turn counter
    while(1){ //until a winner
      if(player[0].checkWin() || player[1].checkWin() || player[2].checkWin() || player[3].checkWin()){
        turnCountTotal+=turnCount;
        turnCount = 0;
        break;
      }
      else{
        for(int j=0; j<4; j++){
          player[j].spin();
          player[j].addPiece();
          turnCount++;
          //cout << "Turn Count: " << turnCount << endl; //debug
        }

      }
    } // end while

  } // end games played
  average = (float)turnCountTotal/NUM_GAMES;
  //cout << "Turn Count: " << turnCountTotal << endl;
  cout << "Average Turns: " << average << endl;
  cout << "Time Taken: " << average*PLAYTIME << " seconds." << endl;

}
