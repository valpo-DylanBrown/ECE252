#include <iostream>
#include <time.h>
using namespace std;
#define NUM_DICE 5
#define NUM_GAMES 1000000000

class Yahtzee {
private:
  int die[NUM_DICE];
public:
  Yahtzee();
  void roll();
  int countMatches(int x);
  bool isFiveOfAKind();
  bool isFourOfAKind();
  bool isThreeOfAKind();
  /*void print(){
    for(int i = 0; i<NUM_DICE; i++){
      cout << die[i] << " ";
    }
    cout << endl;
  }*/
};
Yahtzee::Yahtzee(){
  //dice at zero (NO ROLL)
  for(int i=0; i<NUM_DICE;i++){
    die[i] = 0;
  }

}
void Yahtzee::roll(){
  for(int i =0; i<NUM_DICE; i++){
    die[i] = rand() %6 +1;
  }
}
int Yahtzee::countMatches(int x){
  int matchCount = 0;
  for(int i=0; i<NUM_DICE; i++){
    if(x == die[i]){
      matchCount++;
    }
  }
  return matchCount;
}
bool Yahtzee::isFiveOfAKind(){
  for(int i=1; i<=6; i++){
    if(countMatches(i) == 5){
      return true;
    }
  }
  return false;
}
bool Yahtzee::isFourOfAKind(){
  if(isFiveOfAKind() == true){
    return true;
  }
  else{
    for(int i=1; i<=6; i++){
      if(countMatches(i) == 4){
        return true;
      }
    }
  }
return false;
}
bool Yahtzee::isThreeOfAKind(){
  if(isFourOfAKind() == true){
    return true;
  }
  else{
    for(int i=1; i<=6; i++){
      if(countMatches(i) == 3){
        return true;
      }
    }
  }
return false;
}

int main(){
  srand(time(NULL));
  int threeCount = 0;
  int fourCount = 0;
  int fiveCount = 0;
  float percentThreeKind, percentFourKind, percentFiveKind = 0.0;
  for(int i=0; i<NUM_GAMES; i++){
    Yahtzee game;
    game.roll();
    //game.print();
    //for(int i=1; i<=6; i++){
      //cout << "#" << i << ": " << game.countMatches(i) << endl;
    //}
    if(game.isFiveOfAKind() == true){
      fiveCount++;
    }
    if(game.isFourOfAKind() == true){
      fourCount++;
    }
    if(game.isThreeOfAKind() == true){
      threeCount++;
    }
    //cout << "FiveOAK? " << game.isFiveOfAKind() << endl;
    //cout << "FourOAK? " << game.isFourOfAKind() << endl;
    //cout << "ThreeOAK? " << game.isThreeOfAKind() << endl;
  }
  percentFiveKind = (float) fiveCount/NUM_GAMES*100;
  percentFourKind = (float) fourCount/NUM_GAMES*100;
  percentThreeKind = (float) threeCount/NUM_GAMES*100;
  //cout << "Five Count: " << fiveCount << endl;
  //cout << "Four Count: " << fourCount << endl;
  //cout << "Three Count: " << threeCount << endl;
  cout << "FiveOAK Percent: " << percentFiveKind << endl;
  cout << "FourOAK Percent: " << percentFourKind << endl;
  cout << "ThreeOAK Percent: " << percentThreeKind << endl;

}
