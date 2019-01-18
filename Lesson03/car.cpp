#include <iostream>
using namespace std;

class Car {
  private:
    float cost;
    int weight;
    int year;
    float currSpeed;
    float gasLevel;
  public:
    Car();
    Car(int newYear, float gasLevel);
    void setSpeed(float mph);
    void stop();
    float getSpeed();
};

Car:: Car(){
  cout << "Welcome to your new car!" << endl;
  year = 2019;
  gasLevel = 1.0;
  currSpeed = 0;

}

Car:: Car(int newYear, float gasLevel){
  cout << "Welcome to your used car!" << endl;
  year = newYear;
  gasLevel = gasLevel;
  currSpeed = 0;
}

void Car:: setSpeed(float mph){
  currSpeed = mph;
}
void Car:: stop(){
  currSpeed = 0;
}
float Car:: getSpeed(){
  return currSpeed;
}


int main(){
  Car* buick = new Car();
  buick  -> setSpeed(88);
  int x = buick->getSpeed();

  Car* oldIron = new Car(1989, 0.1);
  oldIron -> setSpeed(29);
  cout << oldIron->getSpeed() << endl;
  //cout << x << endl;
}
