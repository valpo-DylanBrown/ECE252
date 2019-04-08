#include <iostream>
#include <time.h>


#define NUM_GAMES 1000000 //number of games being played
#define NUM_BODY_PARTS 6 // number of game bodyPieceCount
#define NUM_LEGS 6
#define NUM_PLAYERS 2

/*-----------------------
MILTON BRADLEY'S COOTIE
0 -- HEAD
1 -- THORAX
2 -- Antenna
3 -- Eyes
4 -- Mouth
5 -- Legs
-----------------------*/

using namespace std;

class Cootie { //Brown
	private:
		int body[NUM_BODY_PARTS]; // //symbolizes piece for players
    int legs[NUM_LEGS]; //for counting legs
		int bodyPieceCount; //running total of piece count
    int legCount; //running total of legs
    int totalCount; //total count of pieces
		bool head, thorax; //to implement order
		int lastPartLeg; //running count of leg being last
		bool last; //to stop leg from counting over multiple turns
		void add(int x); //simplifies addPiece()

	public:
		Cootie() {initial();} //call initial
		void initial(); //intializes array
		void addPiece(); //adds piece (also checks if piece is present)
		bool checkWin(); //checks for win
		int spin(); //spins random int 0-5
		int getLastPartLeg(){return lastPartLeg;} //return the leg count
};

void Cootie::initial() { //Brown
	for(int i=0; i<NUM_BODY_PARTS; i++) { //fills array with zeros to indicate no piece
		body[i]=0;
	}
  for(int i=0; i<NUM_LEGS; i++) { //fills array with zeros to indicate no piece
		legs[i]=0;
	}
	//initilize vars
	bodyPieceCount=0;
  legCount = 0;
  totalCount = 0;
	head = false;
	thorax = false;
	lastPartLeg = 0;
	last = true;
}

void Cootie::add(int x){ //Brown
	if(x == 5) { //if its a leg
		if(legs[legCount] == 0){ // if it is not there
			legs[legCount] = 1; // set it to one
			legCount++; //increase legCount
			//cout << "Leg Added | Leg Count: " << legCount << endl; //debug
			if(legCount == 6){ //if all legs
				body[x] = 1; //mark it there
				bodyPieceCount++;
			}
		}
	}
	else{
		if(body[x]==0) //if it is zero, replace it
		{
			body[x]=1;
			bodyPieceCount++;
			//cout << "Added piece: " << x << endl; //debug
			if(x == 0){ // if current is zero
				head = true; //set head to true
			}
			if (x == 1 && head == true){ //if current is 1 and head is true
				thorax = true; //set thorax true
			}
		} //else do nothing
		//else{cout << "Piece already here!" << endl;}//debug
	}
}

void Cootie::addPiece() { //Brown
	int current=spin(); //random num
	//cout << current << endl; //debug
  if (current == 0 || body[0] == 1){ //look for a head or to add a head
		if(head == false){ // if its not there, add it
			add(0);
		}
    if(current == 1 || body[1] == 1){ //look for thorax or add a thorax
			if(thorax == false && head == true){ //if thorax hasnt been added but head has
				add(1); // add it
			}
      if(body[0] == 1 && body[1] == 1){ //if thorax and head
  			add(current); // add it
      }
    }
    //else{cout << "You need a thorax" << endl;} //debug
  }
  //else{cout << "You need a head!" << endl;} //debug
}

bool Cootie::checkWin() { //Brown
  totalCount = bodyPieceCount + legCount; //finished product
	for(int i = 0; i<NUM_BODY_PARTS+NUM_LEGS;i++){
		if(bodyPieceCount == 5 && legCount == 5 && last == true){ //stats for last being leg
			lastPartLeg++;
			last = false;
		}
	}
	if(totalCount==(NUM_BODY_PARTS+NUM_LEGS)){
		last = true;
		return true;
	}
	else return false;
}

int Cootie::spin() { //Brown
	return rand() %6; //random num 0-5
}


int main(){ //Brown
  srand(time(NULL)); //seed random
	int roundTotal;
	int playerOneGamesWon, playerTwoGamesWon = 0;
	int lastLegTotal = 0;
	for(int i = 0; i<NUM_GAMES; i++){
		//cout << "GAME #: " << i << endl << endl; //debug
		Cootie player[NUM_PLAYERS];
		bool notFound = true;
		int rounds = 0;
	  while(notFound){ //until a winner
			for(int i = 0; i<NUM_PLAYERS; i++){ // check for a winner
				if(i == NUM_PLAYERS-1){
					rounds++;
				}
				if(player[i].checkWin()){
					//cout << "Player " << i << " wins!" << endl; //debug
					roundTotal += rounds;
					lastLegTotal += player[i].getLastPartLeg();
					if(i == 0){
						playerOneGamesWon++;
					}
					else if(i==1){
						playerTwoGamesWon++;
					}
					else{cout << "ERROR" << endl;}
					notFound = false; // break while
					break;
					}
				//cout << "P" << i << " turn." << endl; // debug
				player[i].spin();
				player[i].addPiece();
				}
	    }
		}
		//cout << "TOTAL ROUNDS: " << roundTotal << endl; //debug
		float averageRounds = (float) roundTotal/NUM_GAMES;
		cout << "Average Number of Rounds: " << averageRounds << endl;
		//cout << "P1 WINS: " << playerOneGamesWon << endl; //debug
		float averageFirstRollWins = (float) playerOneGamesWon/NUM_GAMES;
		cout << "Average Wins from First Roll: " << averageFirstRollWins << endl;
		//cout << "LAST LEG: " << lastLegTotal << endl; //debug
		float finalPieceLeg = (float) lastLegTotal/NUM_GAMES;
		cout << "Chance of Last Piece Leg: " << finalPieceLeg << endl;
}



	/*SAMPLE OUTPUT SHOWING AVERAGES
	4c-32-75-9c-9c-29:project04 dylan$ ./a.out
	Average Number of Rounds: 40.3007
	Average Wins from First Roll: 0.509276
	Chance of Last Piece Leg: 0.936954
	*/
