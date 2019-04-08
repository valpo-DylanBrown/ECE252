#include <iostream>
#include <time.h>
using namespace std;
#define SIZE 343

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


class BST {
	private:
		BinNode* root;  //pointer to root of tree
		void printNode(BinNode* myNode);  //recursively print node
		bool containsNode(BinNode* myNode, int x);  //recursively search
		void insertNode(BinNode* myNode, int x);  //recursively add
	public:
		BST();  //constructor
		void insert(int x);   //insert a number x into the BST
		bool contains(int x); //Search the tree for a number x
		void print();         //print the contents of the tree in order.
};
BST::BST(){
	root = NULL;
}
void BST::printNode(BinNode* myNode){
	if( myNode == NULL){
		return;
	}
	printNode(myNode->getLeft());
  cout << myNode->getData() << " ";
  printNode(myNode->getRight());
}

void BST::insertNode(BinNode* myNode, int x){
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

bool BST::containsNode(BinNode* myNode, int x){
	if(x == myNode->getData()){
		return true;
	}
	if(x >= myNode->getData()){
		if(myNode->getRight()!=NULL){
			return containsNode(myNode->getRight(),x);
		}
	}
	else{
		if(myNode->getLeft()!=NULL){
			return containsNode(myNode->getLeft(),x);
		}
	}
	return false;
}

void BST::print(){
	if(root == NULL){
		return;
	}
	printNode(root);
}

void BST::insert(int x){
	if(root == NULL){
		root = new BinNode(x);
		return;
	}
	insertNode(root, x);
}
bool BST::contains(int x){
	if(root == NULL){
		return false;
	}
	return containsNode(root, x);
}

void shuffle(int array[SIZE], int order){
	int x, y, temp;
	for(int i=0; i<order;i++){
		x = rand() % SIZE+1;
		y = rand() % SIZE+1;
		temp = array[x];
		array[x] = array[y];
		array[y] = temp;
	}
}

int main(){
	srand(time(NULL));
	int multOfSeven[SIZE];
	int x;
	int y;
	int temp;
	BST* bst1 = new BST();
	BST* bst2 = new BST();
	BST* bst3 = new BST();
	//TREES 1 AND 2

	for(int i=2; i<=100; i+=2){
		bst1->insert(i);
	}
	for(int i=100; i>=2; i-=2){
		bst2->insert(i);
	}
	cout << "TREE 1:" << endl;
	bst1->print();
	cout << endl;
	cout << "TREE 2:" << endl;
	bst2->print();
	cout << endl;

	//TREE 3
	for(int i =0; i<=343; i++){
		multOfSeven[i] = i*7;
	}
	shuffle(multOfSeven, 1000);
	cout << "Random Multiples of Seven:" << endl;
	for(int i =0; i<=343; i++){
		cout << multOfSeven[i] << " ";
	}
	cout << endl;
	for(int i=0; i<=SIZE; i++){
		bst3->insert(multOfSeven[i]);
	}
	cout <<"TREE 3:" << endl;
	bst3->print();
	cout << endl;
	cout << endl;
	cout << "The tree " << (bst3->contains(700) ? "contains":"does not contain") << " 700." << endl;
	cout << "The tree " << (bst3->contains(1000) ? "contains":"does not contain") << " 1000." << endl;
	return 0;
}

/* OUTPUT
4c-32-75-9c-9c-29:lesson18 dylan$ ./a.out
TREE 1:
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100
TREE 2:
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100
Random Multiples of Seven:
0 2030 2219 70 1134 420 1771 1001 2380 413 1967 644 1393 77 1204 378 602 1043 336 2387 917 84 1337 1232 1190 756 1428 2303 1554 1540 679 1141 2037 1449 1631 553 1463 1015 826 791 2079 847 315 406 609 273 945 1820 1470 182 1197 1834 1400 2317 329 2149 833 630 1589 399 2065 1995 490 1274 1645 105 1288 1561 665 385 357 448 1848 1078 2121 455 2156 1939 1330 1071 427 2240 1358 819 161 1547 154 1687 574 2093 1155 777 2107 1344 721 2128 1239 1974 2331 1099 364 2100 2247 1435 483 1617 1575 1729 1421 112 511 1911 973 2310 1533 1638 1162 7 1904 168 1484 714 2205 1036 623 14 133 21 889 651 49 1988 2163 1582 693 588 1120 441 175 1666 1792 1624 1302 462 2289 1925 1022 63 2359 525 980 637 504 2296 518 728 840 1799 294 2044 1981 2352 1267 1897 2324 938 581 1883 1253 2191 1057 616 1225 280 1680 2114 868 343 1491 1113 98 2135 392 686 1309 2072 350 231 259 1414 1442 91 1764 1750 1211 469 2177 1176 798 784 952 1953 1610 2051 2058 2142 1148 903 2254 658 1701 1603 1106 42 210 1757 2282 119 2009 1029 1281 595 2373 147 805 1932 497 217 1085 1050 287 1708 2002 1785 196 1316 1183 2394 266 322 1715 875 1862 1876 532 994 1260 2170 1456 1092 1869 2275 1841 910 1064 1743 2184 189 1218 2212 1372 1855 1379 1127 1526 567 1498 1386 1960 1596 700 1323 1918 812 959 56 735 2345 1659 1673 2401 924 2366 861 763 742 1407 1652 1568 1295 308 2226 672 2198 1505 1512 2016 546 245 1827 1813 1694 224 1351 1477 301 966 1946 882 1736 1169 931 1722 203 238 560 1365 2233 126 140 1778 539 1806 2268 1519 770 749 434 2338 35 707 1246 1890 476 28 2086 2023 854 987 252 2261 371 896 1008
TREE 3:
0 7 14 21 28 35 42 49 56 63 70 77 84 91 98 105 112 119 126 133 140 147 154 161 168 175 182 189 196 203 210 217 224 231 238 245 252 259 266 273 280 287 294 301 308 315 322 329 336 343 350 357 364 371 378 385 392 399 406 413 420 427 434 441 448 455 462 469 476 483 490 497 504 511 518 525 532 539 546 553 560 567 574 581 588 595 602 609 616 623 630 637 644 651 658 665 672 679 686 693 700 707 714 721 728 735 742 749 756 763 770 777 784 791 798 805 812 819 826 833 840 847 854 861 868 875 882 889 896 903 910 917 924 931 938 945 952 959 966 973 980 987 994 1001 1008 1015 1022 1029 1036 1043 1050 1057 1064 1071 1078 1085 1092 1099 1106 1113 1120 1127 1134 1141 1148 1155 1162 1169 1176 1183 1190 1197 1204 1211 1218 1225 1232 1239 1246 1253 1260 1267 1274 1281 1288 1295 1302 1309 1316 1323 1330 1337 1344 1351 1358 1365 1372 1379 1386 1393 1400 1407 1414 1421 1428 1435 1442 1449 1456 1463 1470 1477 1484 1491 1498 1505 1512 1519 1526 1533 1540 1547 1554 1561 1568 1575 1582 1589 1596 1603 1610 1617 1624 1631 1638 1645 1652 1659 1666 1673 1680 1687 1694 1701 1708 1715 1722 1729 1736 1743 1750 1757 1764 1771 1778 1785 1792 1799 1806 1813 1820 1827 1834 1841 1848 1855 1862 1869 1876 1883 1890 1897 1904 1911 1918 1925 1932 1939 1946 1953 1960 1967 1974 1981 1988 1995 2002 2009 2016 2023 2030 2037 2044 2051 2058 2065 2072 2079 2086 2093 2100 2107 2114 2121 2128 2135 2142 2149 2156 2163 2170 2177 2184 2191 2198 2205 2212 2219 2226 2233 2240 2247 2254 2261 2268 2275 2282 2289 2296 2303 2310 2317 2324 2331 2338 2345 2352 2359 2366 2373 2380 2387 2394 2401

The tree contains 700.
The tree does not contain 1000.
*/
