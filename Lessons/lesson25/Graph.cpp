#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX_EDGES 100

//forward declaration, required since edges contain nodes and nodes contain edges.
class Node;

//An objeczt of this class represents an edge in the graph.
class Edge
{
	private:
		Node *orgNode;//the originating vertex
		Node *dstNode;//the destination vertex
		unsigned int cost;//cost of the edge

	public:
		Edge(Node *firstNode, Node *secNode, unsigned inCost)
		{orgNode = firstNode; dstNode = secNode; cost = inCost;}

		Node* getDstNode() {return dstNode;}
		Node* getOrgNode() {return orgNode;}
		unsigned int getCost() {return cost;}
};

//An object of this class holds a vertex of the graph
class Node
{
	private:
		string name;
		Edge* edgeList[MAX_EDGES];
		int numEdges;
		bool visited;

	public:
		Node() { numEdges = 0; name = ""; visited=false; }
		Node(string id) { numEdges = 0; name = id; visited=false; }
		string getName(){return name;}
		bool getVisited(){return visited;}

		void preOrderPrint(){
			//output name of current node.
      cout << getName() << endl;
			//set current node's visited to true.
      visited = true;
			//loop over all edges attached to this node:
      for(int i=0; i<numEdges; i++){
        //if an edge's destination node is unvisited,
        if(edgeList[i]->getDstNode()->getVisited() == false){
          //then call preOrderPrint on that node.
          edgeList[i]->getDstNode()->preOrderPrint();
        }
      }

		}

		void addAdjNode(Edge *adj)
		{
			//add adj to the end of edgeList  (edgeList[numEdges])
      edgeList[numEdges] = adj;
			//increment numEdges for this node.
      numEdges++;
		}
};


int main () {
	//insert code to create nodes here.
  Node* Charlie = new Node("Charlie");
  Node* Bob = new Node("Bob");
  Node* Daniel = new Node("Daniel");
  Node* Alice = new Node("Alice");
  Node* Ed = new Node("Ed");

	//insert code to create edges here.
  Edge* e1 = new Edge(Charlie, Daniel, 2);
  Edge* e2 = new Edge(Daniel, Charlie, 8);
  Edge* e3 = new Edge(Daniel, Ed, 4);
  Edge* e4 = new Edge(Daniel, Alice, 5);
  Edge* e5 = new Edge(Alice, Bob, 20);
  Edge* e6 = new Edge(Bob, Charlie, 10);
	//insert code to add node adjacencies here.
  Charlie->addAdjNode(e1);
  Bob->addAdjNode(e6);
  Daniel->addAdjNode(e2);
  Daniel->addAdjNode(e3);
  Daniel->addAdjNode(e4);
  Alice->addAdjNode(e5);

	//pre-order print on node Charlie (later task).
  Charlie->preOrderPrint();
	return 0;
}

/*OUTPUT
4c-32-75-9c-9c-29:lesson25 dylan$ ./a.out
Charlie
Daniel
Ed
Alice
Bob
*/
