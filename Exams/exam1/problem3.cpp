#include <iostream>
using namespace std;

class Animal{
protected:
  string cowSound;
  string catSound;
  string foxSound;
public:
  Animal(){};
  virtual void speak() = 0;
};

class Cow : public Animal{
public:
  Cow(){cowSound= "Moo";}
  void speak(){
    cout << "The cow says: " << cowSound << endl;
  }
};
class Cat : public Animal{
public:
  Cat(){catSound = "Meow";}
  void speak(){
    cout << "The cat says: " << catSound << endl;
  }
};
class Fox : public Animal{
public:
  Fox(){foxSound= "Ow-wow-wow-wow";}
  void speak(){
    cout << "The fox says: " << foxSound << endl;
  }
};

int main(){
  Animal* cow = new Cow();
  Animal* cat = new Cat();
  Animal* fox = new Fox();

  cow->speak();
  cat->speak();
  fox->speak();
}

/*
----------------------------------------------
------------------OUTPUT----------------------
----------------------------------------------
$ a
The cow says: Moo
The cat says: Meow
The fox says: Ow-wow-wow-wow
*/
