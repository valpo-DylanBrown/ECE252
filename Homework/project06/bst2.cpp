#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

#define MAX_EL 31

class BinNode {
private:
		int data;
		BinNode* left;
		BinNode* right;
	public:
		BinNode() { left = NULL; right = NULL; data = 0; }
		BinNode (int x) { left = NULL; right = NULL; data = x; }

		BinNode* getLeft() { return left; }
		BinNode* getRight() {return right; }
		int getData() { return data; }

		void setData (int x) { data = x; }
		void setRight (BinNode* newRight) { right = newRight; }
		void setLeft (BinNode* newLeft) { left = newLeft; }
};

class BST2 {

	private:
		BinNode* root;
		void printNode(BinNode* myNode);  //already written in ICE
		bool containsNode(BinNode* myNode,int x); //already written in ICE
		void insertNode(BinNode* myNode, int x); //already written in ICE
		void trimLeft(BinNode* myNode); //removes left child of myNode
		void trimRight(BinNode* myNode);  //removes right child of myNode
		void trimRoot();   //removes root node of entire tree
		int getMin(BinNode* myNode);  //helper #1 : find min of subtree myNode
		void removeNode(BinNode* myNode, int x);  //helper #2: remove node with value x from subtree of myNode.

		//NEW recursive print functions to help you with debugging
		void printFlattenedNode(BinNode* myNode, int* array, int level);
		void printAsTreeNode(BinNode* myNode, int level);

	public:
		BST2();  //already written in ICE
		void insert(int x);  //already written in ICE
		bool contains(int x);  //already written in ICE
		void print();  //already written in ICE
		void remove(int x);   //public function to remove x from tree

		//Debugging public function prints
		void printFlattened();
		void printAsTree();
};


void BST2::printNode(BinNode* myNode) {//recursively print in order.  called by public function print()
  if( myNode == NULL){
		return;
	}
	printNode(myNode->getLeft());
  cout << myNode->getData() << " ";
  printNode(myNode->getRight());
}


bool BST2::containsNode(BinNode* myNode, int x) {
  if(myNode == NULL){
    return false;
  }
  if(x == myNode->getData()){
		return true;
	}
	if(x >= myNode->getData()){
			return containsNode(myNode->getRight(),x);
	}
	else{
			return containsNode(myNode->getLeft(),x);
	}
	//return false;
}


void BST2::insertNode(BinNode* myNode, int x) {
  if(x >= myNode->getData()){
    if(myNode->getRight() == NULL){
      BinNode* temp = new BinNode(x);
      myNode->setRight(temp);
      return;
    }
    insertNode(myNode->getRight(), x);
  }
  else{
    if(myNode->getLeft() == NULL){
      BinNode* temp = new BinNode(x);
      myNode->setLeft(temp);
      return;
    }
    insertNode(myNode->getLeft(), x);
  }
}

void BST2::removeNode(BinNode* myNode, int x) {  //remove node with value x from subtree of myNode.
  //error check
	/*
  if((myNode->getData() == x) && ((myNode->getRight()->getData() || myNode->getLeft()->getData()) != x)){
    cout << "Wrong, too far" << endl;
    return;
  }*/
	//Does x belong to the left subtree?
  if(x < myNode->getData()){ //left
    if(myNode->getLeft() == NULL){  //If the left subtree is NULL, the value is not in the tree.  Return.
      return;
    }
    else if(x == myNode->getLeft()->getData()){//If the left child matches the value to be removed, trimLeft.
      trimLeft(myNode);
    }
    else{//otherwise, must recursively removeNode on left child to look deeper.
      removeNode(myNode->getLeft(), x);
    }
  }
	else{ //right
    if(myNode->getRight() == NULL){  //If the right subtree is NULL, the value is not in the tree.  Return.
      return;
    }
    else if(x == myNode->getRight()->getData()){//If the right child matches the value to be removed, trimRight.
      trimRight(myNode);
    }
    else{//otherwise, must recursively removeNode on right child to look deeper.
      removeNode(myNode->getRight(), x);
    }
  }
}

void BST2::trimLeft(BinNode* myNode) {  //Remove the left child of myNode
  //cout << "TRIM LEFT" << endl;
	//Make a temporary pointer to the left child.
  BinNode* leftChild = myNode->getLeft();
  int val;
	//CASE 1: left child has no children: set current left child pointer to NULL.
  if((leftChild->getLeft() == NULL) && (leftChild->getRight() == NULL)){
    myNode->setLeft(NULL);
    delete leftChild;
  }
	//CASE 2A: left child has no left child: set current left to single left grandchild.
  else if((leftChild->getLeft() == NULL) && (leftChild->getRight() != NULL)){
    myNode->setLeft(leftChild->getRight());
    delete leftChild;
  }
	//CASE 2B: left child has no right child: set current left to single left grandchild.
  else if((leftChild->getLeft() != NULL) && (leftChild->getRight() == NULL)){
    myNode->setLeft(leftChild->getLeft());
    delete leftChild;
  }
  else{
		//cout << "2kidTL" << endl;
    val = getMin(leftChild->getRight());
    removeNode(leftChild, val);
    leftChild->setData(val);
  }
	//CASE 3: left child has two children
	  //find minimum value of left child's right subtree using getMin
	  //remove the node with that value using removeNode
	  //set value of current left child to the minimum value found.
}

void BST2::trimRight(BinNode* myNode) {  //trim right child of myNode
	//same is trimLeft, but on right child.
  BinNode* rightChild = myNode->getRight();
  int val;
  //cout << "TRIM RIGHT" << endl;
  if((rightChild->getLeft() == NULL) && (rightChild->getRight() == NULL)){
    myNode->setRight(NULL);
    delete rightChild;
  }
  //CASE 2A: left child has no left child: set current left to single left grandchild.
  else if((rightChild->getLeft() == NULL) && (rightChild->getRight() != NULL)){
    myNode->setRight(rightChild->getRight());
    delete rightChild;
  }
  //CASE 2B: left child has no right child: set current left to single left grandchild.
  else if((rightChild->getLeft() != NULL) && (rightChild->getRight() == NULL)){
    myNode->setRight(rightChild->getLeft());
    delete rightChild;
  }
  else{
		//cout << "2kidTR" << endl;

    val = getMin(rightChild->getRight());
		//cout << "DATA: " << rightChild->getData() << "\tVAL:" << val << endl;
		removeNode(rightChild, val);
    rightChild->setData(val);
  }
}

void BST2::trimRoot() {  //remove root node from tree.
  int val;
	//If root is NULL, return from empty tree.
	//CASE 1: Root has no children, set root to NULL.
  if((root->getLeft() == NULL) && (root->getRight() == NULL)){
    root = NULL;
  }
  //CASE 2A: Root has no left child, set root to root's getRight
  else if((root->getLeft() == NULL) && (root->getRight() != NULL)){
    root = root->getRight();
  }
  //CASE 2B: Root has no right child, set root to root's getLeft
  else if((root->getLeft() != NULL) && (root->getRight() == NULL)){
    root = root->getLeft();
  }
  /* CASE 3: Root has two children
   *  find minimum value in right subtree.
   *  Remove the node with that minimum value.
   *  Set root's data to that minimum value.
  */
  else{
    val = getMin(root->getRight());
    removeNode(root, val);
    root->setData(val);
  }
}

int BST2::getMin(BinNode* myNode) {
	//find and return smallest value in subtree with myNode as root.
	//if subtree is myNode is NULL, return INT_MIN

  if(myNode == NULL){
    cout << "Error: called getMin on NULL node" << endl;
    return INT_MIN;
  }

  if(myNode->getLeft() == NULL){
    return myNode->getData();
  }
  return getMin(myNode->getLeft());
}


BST2::BST2() { root = NULL; }

void BST2::insert (int x) {
	if (root == NULL) {
		BinNode* tmp = new BinNode(x);
		root = tmp;
	}
	else insertNode(root, x);
}

void BST2::remove (int x) {
	//If root is NULL, return from empty tree.
	//if root's data matches number to be removed, trimRoot.
	//else, call recursive function removeNode on root.
  if(root == NULL){
    return;
  }
  if(root->getData() == x){
    trimRoot();
    return;
  }
  removeNode(root, x);
}



bool BST2::contains (int x) {
	return containsNode(root, x);
}


void BST2::print () {
	printNode(root);
	cout << endl;
}

int main () {

		BST2* myBST2 = new BST2();

		myBST2->insert(4);
		myBST2->insert(6);
		myBST2->insert(2);
		myBST2->insert(9);
		myBST2->insert(1);
		myBST2->insert(19);
		myBST2->insert(3);
		myBST2->print();
		myBST2->remove(3);
		myBST2->print();
		myBST2->remove(19);
		myBST2->print();
		myBST2->remove(6);
		myBST2->print();

		srand(12);
		for (int i=0; i<20; i++ ) {
			myBST2->insert(rand()%200);
		}
		myBST2->print();

		myBST2->remove(32);
		myBST2->print();
		myBST2->remove(1);
		myBST2->print();
		myBST2->remove(2);
		myBST2->print();
		myBST2->remove(150);
		myBST2->print();
		myBST2->remove(65);
		myBST2->print();
		//remove some numbers not in the tree
		myBST2->remove(8);
		myBST2->remove(190);
		myBST2->remove(100);

		//insert some more numbers...
		for(int i=0; i<10; i++) {
			myBST2->insert(rand()%200);
		}
		myBST2->print();

		srand(12);
		for (int i=0; i<20; i++ ) {
			myBST2->remove(rand()%200);
		}
		myBST2->print();

		myBST2->remove(9);
		myBST2->print();
		myBST2->remove(4);
		myBST2->print();


		return 0;
}


//below are the function definitions for the debugging printing************
void BST2::printAsTree() {
	printAsTreeNode(root, 0);
}


void BST2::printAsTreeNode(BinNode* myNode, int level) {

	if (myNode == NULL) return;
	printAsTreeNode(myNode->getRight(), level+1);
	for (int i=0; i<level; i++) // Indent to level
		cout << "   ";
	cout << myNode->getData() << "\n"; // Print node value
	printAsTreeNode(myNode->getLeft(), level+1);
}

void BST2::printFlattened() {

	int data[MAX_EL];

	for (int i=0; i < MAX_EL; i++) {
		data[i] = INT_MIN;
	}

	if (root==NULL) return;

	printFlattenedNode(root, data, 0);


	cout << endl << "Flattened Tree: [";
	//print array
	for (int i=0; i < MAX_EL; i++) {
		if (data[i] != INT_MIN) cout << data[i];
		else cout << "-";
		cout << " ";
	}
	cout << "]" << endl;

}


void BST2::printFlattenedNode(BinNode* myNode, int* array, int level) {

	if (level >= MAX_EL) return;

	array[level] = myNode->getData();

	if (myNode->getLeft() != NULL) printFlattenedNode(myNode->getLeft(), array, 2*level+1);
	if (myNode->getRight() != NULL) printFlattenedNode(myNode->getRight(), array, 2*level+2);

}







/* OUTPUT
Dylan@DYLAN-PC /c/users/dylan/documents/github/ece252/homework/project06
$ a
1 2 3 4 6 9 19
1 2 4 6 9 19
1 2 4 6 9
1 2 4 9
1 2 4 9 12 28 29 29 32 52 64 65 77 78 81 99 126 147 150 158 165 170 171 181
1 2 4 9 12 28 29 29 52 64 65 77 78 81 99 126 147 150 158 165 170 171 181
2 4 9 12 28 29 29 52 64 65 77 78 81 99 126 147 150 158 165 170 171 181
4 9 12 28 29 29 52 64 65 77 78 81 99 126 147 150 158 165 170 171 181
4 9 12 28 29 29 52 64 65 77 78 81 99 126 147 158 165 170 171 181
4 9 12 28 29 29 52 64 77 78 81 99 126 147 158 165 170 171 181
4 9 12 25 28 29 29 39 52 53 54 64 77 78 81 90 99 126 137 141 147 155 156 158 165
 170 171 177 181
4 9 25 39 53 54 90 137 141 155 156 177
4 25 39 53 54 90 137 141 155 156 177
25 39 53 54 90 137 141 155 156 177
*/
