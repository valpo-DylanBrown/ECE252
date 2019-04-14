#include <stdlib.h>
#include <iostream>
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
void preOrderPrint(BinNode* x){
  if( x == NULL){
    return;
  }
  cout << x->getData() << " ";
  postOrderPrint(x->getLeft());
  postOrderPrint(x->getRight());

};
void inOrderPrint(BinNode* x){
  if( x == NULL){
    return;
  }
  inOrderPrint(x->getLeft());
  cout << x->getData() << " ";
  inOrderPrint(x->getRight());
};

int main(){
  BinNode* t1 = new BinNode();
  BinNode* t2 = new BinNode();
  BinNode* t3 = new BinNode();
  BinNode* t4 = new BinNode();
  BinNode* t5 = new BinNode();
  BinNode* t6 = new BinNode();
  BinNode* t7 = new BinNode();
  BinNode* t8 = new BinNode();

  t1->setData('1');
  t1->setLeft(t2);
  t1->setRight(t3);

  t2->setData('2');
  t2->setLeft(t4);
  t2->setRight(t5);

  t3->setData('3');
  t3->setLeft(NULL);
  t3->setRight(NULL);

  t4->setData('4');
  t4->setLeft(t6);
  t4->setRight(NULL);

  t5->setData('5');
  t5->setLeft(t7);
  t5->setRight(t8);

  t6->setData('6');
  t6->setLeft(NULL);
  t6->setRight(NULL);

  t7->setData('7');
  t7->setLeft(NULL);
  t7->setRight(NULL);

  t8->setData('8');
  t8->setLeft(NULL);
  t8->setRight(NULL);

  cout << "IN ORDER" << endl;
  inOrderPrint(t1);
  cout << endl;
  cout << "POST ORDER" << endl;
  postOrderPrint(t1);
  cout << endl;
  cout << "PRE ORDER" << endl;
  preOrderPrint(t1);
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
