#include <iostream>
using namespace std;
#define NUM_RANKS 13
#define NUM_SUITS 4

class Card {

	private:
		int rank;  //A=1, 2=2 .., 10=10, J=11, Q=12, K=13
		char suit;  //SHCD
	public:
		Card(){suit='S'; rank = 1;};
		//default constructor makes the card into an Ace of Spades
		Card(int newRank, char newSuit){suit = newSuit; rank=newRank;};
		//non-default (intializer) constructor
		int getRank(){return rank;};  //return the rank.
		char getSuit();  //return the suit.
		void setRank(int newRank){ rank = newRank;};  //set the rank.
		void setSuit(char newSuit){suit=newSuit;};  //set the suit.
		void print();  //print the card value to the screen.
};

char Card:: getSuit(){
	return suit;
}

void Card::print()  {  //Card:: is the "object identifier"
	if (rank==1) cout << "A";
	else if (rank==11) cout << "J";
	else if (rank==12) cout << "Q";
	else if (rank==13) cout << "K";
	else cout << rank;

	cout << suit;
	//cout << endl;
}


//function prototypes:
void perfectShuffle (Card * cardDeck);
void printDeck (Card * cardDeck);

int main() {
	Card * firstCard = new Card();  //default constructor
	//firstCard -> print();

	Card* secondCard = new Card(12, 'H');
	//secondCard->print();

	Card* deck = new Card[NUM_RANKS * NUM_SUITS];

	for(int i =0; i<NUM_RANKS;i++){
		deck[i] = Card(i+1, 'S');
		deck[i+1*NUM_RANKS] = Card(i+1, 'H');
		deck[i+2*NUM_RANKS] = Card(i+1, 'C');
		deck[i+3*NUM_RANKS] = Card(i+1, 'D');
	}
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);
	perfectShuffle(deck);
	printDeck(deck);

	return 0;

}




//***********These are sub-functions for the MAIN program... not class member methods
void printDeck (Card* cardDeck){
	for (int i=0; i<NUM_RANKS*NUM_SUITS; i++){  //print all 52 cards.
		cardDeck[i].print();
		cout << " ";
	}
	cout << endl << endl;
}

void perfectShuffle (Card* cardDeck) {
	Card * tmpDeck = new Card[NUM_RANKS*NUM_SUITS];
	for (int i=0; i<NUM_RANKS*NUM_SUITS/2; i++){
		tmpDeck[2*i] = cardDeck[i];  //take care of even cards.
		tmpDeck[2*i+1] = cardDeck[i+NUM_RANKS*NUM_SUITS/2];  //take care of odd cards.
	}  //cards are now shuffled in tmpDeck
	for (int i=0; i<NUM_RANKS*NUM_SUITS; i++){
		cardDeck[i]=tmpDeck[i];
	}//copies tmpDeck back into cardDeck.
}
