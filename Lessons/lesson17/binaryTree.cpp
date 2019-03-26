#include <stdlib.h>
#include <iostream>
#define PLUS '+'
#define MINUS '-'
#define MULTIPLY '*'
#define DIVIDE '/'
using namespace std;

class BinNode{
private:
  char payload;
  BinNode* leftChild;
  BinNode* rightChild;
public:
  //getters and setters
  char getData(){return payload;};
  BinNode* getLeft(){return leftChild;};
  BinNode* getRight(){return rightChild;};

  void setData(char x){payload = x;};
  void setLeft(BinNode* nextLeft){leftChild = nextLeft;};
  void setRight(BinNode* nextRight){rightChild = nextRight;};
};

void postOrderPrint(BinNode* x){
  if( x == NULL){
    return;
  }
  postOrderPrint(x->getLeft());
  postOrderPrint(x->getRight());
  cout << x->getData() << " ";
};
void inOrderPrint(BinNode* x){
  if( x == NULL){
    return;
  }
  if(x->getData() == PLUS || MINUS || MULTIPLY || DIVIDE){
    cout << "(";
  }
  inOrderPrint(x->getLeft());
  cout << x->getData() << " ";
  inOrderPrint(x->getRight());
  if(x->getData() == PLUS || MINUS || MULTIPLY || DIVIDE){
    cout << ")";
  }
};

int main(){
  BinNode* sym1 = new BinNode();
  BinNode* sym2= new BinNode();
  BinNode* sym3 = new BinNode();
  BinNode* sym4 = new BinNode();
  BinNode* sym5 = new BinNode();
  BinNode* sym6 = new BinNode();
  BinNode* t1 = new BinNode();
  BinNode* t2 = new BinNode();
  BinNode* t3 = new BinNode();
  BinNode* t4 = new BinNode();
  BinNode* t5 = new BinNode();
  BinNode* t6 = new BinNode();
  BinNode* t7 = new BinNode();
  sym1->setData('*');
  sym1->setRight(t1);
  sym1->setLeft(sym2);

  sym2->setData('-');
  sym2->setLeft(sym3);
  sym2->setRight(sym4);

  sym3->setData('+');
  sym3->setLeft(t2);
  sym3->setRight(t3);

  sym4->setData('/');
  sym4->setLeft(sym5);
  sym4->setRight(t4);

  sym5->setData('+');
  sym5->setLeft(t5);
  sym5->setRight(sym6);

  sym6->setData('*');
  sym6->setLeft(t6);
  sym6->setRight(t7);


  t1->setData('8');
  t1->setLeft(NULL);
  t1->setRight(NULL);

  t2->setData('2');
  t2->setLeft(NULL);
  t2->setRight(NULL);

  t3->setData('3');
  t3->setLeft(NULL);
  t3->setRight(NULL);

  t4->setData('5');
  t4->setLeft(NULL);
  t4->setRight(NULL);

  t5->setData('6');
  t5->setLeft(NULL);
  t5->setRight(NULL);

  t6->setData('9');
  t6->setLeft(NULL);
  t6->setRight(NULL);

  t7->setData('4');
  t7->setLeft(NULL);
  t7->setRight(NULL);


  cout << "POST ORDER" << endl;
  postOrderPrint(sym1);
  cout << endl;
  cout << "IN ORDER" << endl;
  inOrderPrint(sym1);
  cout << endl;

  return 0;
}



/*
=============================
OUTPUT
=============================
4c-32-75-9c-9c-29:Lesson17 dylan$ ./a.out
POST ORDER
2 3 + 6 9 4 * + 5 / - 8 *
IN ORDER
((((2 )+ (3 ))- (((6 )+ ((9 )* (4 )))/ (5 )))* (8 ))
*/
