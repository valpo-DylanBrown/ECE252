#include <iostream>
#include <time.h>
//#define NUM_GAMES 100000 //number of games being played
#define NUM_BODY_PARTS 6 // number of game bodyPieceCount
#define NUM_LEGS 6
//#define NUM_PLAYERS 4
//#define PLAYTIME 5
using namespace std;

class Cootie {
	private:
    //int head, thorax, eyes, antenna, mouth, leg = 0;
		int body[NUM_BODY_PARTS]; // //symbolizes piece for players
    int legs[NUM_LEGS];
		int bodyPieceCount; //running total of piece count
    int legCount;
    int totalCount;

	public:
		Cootie() {initial();}
		void initial(); //intializes array
		void addPiece(); //adds piece (also checks if piece is present)
		//bool checkPiece();
		bool checkWin(); //checks for win
		int spin(); //spins random int 0-5
};

void Cootie::initial() {
	for(int i=0; i<NUM_BODY_PARTS; i++) { //fills array with zeros to indicate no piece
		body[i]=0;
	}
  for(int i=0; i<NUM_LEGS; i++) { //fills array with zeros to indicate no piece
		legs[i]=0;
	}
	bodyPieceCount=0;
  legCount = 0;
  totalCount = 0;
}

void Cootie::addPiece() {
	int current=spin(); //random num
  if (current == 0 || body[0] == 1){
    if(body[0] == 0){
      body[current]=1;
      bodyPieceCount++;
      cout << "Added Head" << endl;
    }
    if(body[0] == 1 && (current == 1 || body[1] == 1)){
      if(body[1] == 0){
        body[current]=1;
        bodyPieceCount++;
        cout << "Added Thorax" << endl;
      }
      if(body[0] == 1 && body[1] == 1){
        if(current == 5) {
          if(legs[legCount] == 0){
            legs[legCount] = 1;
            legCount++;
            cout << "Leg Added | Leg Count: " << legCount << endl;
            if(legCount == 6){
              body[current] = 1;
              bodyPieceCount++;
            }
          }
        }
        else{
          if(body[current]==0) //if it is zero, replace it
          {
            body[current]=1;
            bodyPieceCount++;
            cout << "Added piece: " << current << endl;
          } //else do nothing*/
          else{cout << "Piece already here!" << endl;}
        }
      }
    }
    else{cout << "You need a thorax" << endl;}
  }
  else{cout << "You need a head!" << endl;}
}

bool Cootie::checkWin() {
  totalCount = bodyPieceCount + legCount;
	if(totalCount==NUM_BODY_PARTS+NUM_LEGS){
		return true;
	}
	else return false;
}

int Cootie::spin() {
	return rand() %6;
}


int main(){
  srand(time(NULL));
  Cootie player1;
  Cootie player2;
  while(1){ //until a winner
    if(player1.checkWin()){
      cout << "Player 1 winner" << endl;
      break;
    }
    else if(player2.checkWin()){
      cout << "Player 2 winner" << endl;
      break;

    }
    else{
      //no winners
      cout << "P1 Turn" << endl;
      player1.spin();
      player1.addPiece();
      cout << "P2 Turn" << endl;
      player2.spin();
      player2.addPiece();
    }
  } // end while
}
