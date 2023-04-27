//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "PES1UG20CS601.hpp"
#include "Edge.h"

using namespace std;

int main()
{
	Graph<int, int> myGraph1(true);

	for(int i = 0; i < 5; i++)
		myGraph1.addNode(i);

	vector<vector<int>> edges = {{0, 1, 1},
								 {1, 2, 1},
								 {3, 4, 1}};

	for(auto edge : edges)
		myGraph1.addEdge(edge[0], edge[1], edge[2]);

	cout << "Components : " << endl;
	vector<vector<int>> comps = myGraph1.connectedComponents();
	for(auto comp : comps)
	{
		for(auto node : comp)
			cout << node << " ";

		cout << endl;
	}

	cout << endl;

	Graph<int, int>  myGraph2(false);

	vector<vector<int>> adjMat = {{0,1,1,1,0},
								  {1,0,1,1,1},
								  {1,1,0,1,1},
								  {1,1,1,0,0},
								  {0,1,1,0,0}};

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(adjMat[i][j] == 1)
				myGraph2.addEdge(i, j, 1);

	if(myGraph2.hasCycle())
		cout << "The given graph has a cycle.";
	else
		cout << "This graph does not have a cycle.";

	cout << endl << endl;

	vector<double> katz = myGraph2.katzCentrality(0.25, 0.2);
	cout << "Katz : " << endl;
	for(auto ele : katz)
		cout << ele << " ";

	cout << endl << endl;

	myGraph2.completeEdges();

	cout << endl;

	Graph<int, double> myGraph3(true);
	Graph<int, int> myGraph4(true);

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(adjMat[i][j] == 1)
				myGraph3.addEdge(i, j, random());

	vector<Edge<int, double>> myTree = myGraph3.kruskalMST();

	cout << "Kruskal Edges = " << endl;
	for(auto ele : myTree)
		cout << ele.src << " " << ele.dest << " " << ele.weight << endl;

	cout << endl;

	cout << "Prim Edges = " << endl;
	for(auto ele : myTree)
		cout << ele.src << " " << ele.dest << " " << ele.weight << endl;

	cout << endl;

	vector<int> ucs = myGraph3.uniformCostSearch(0, 3);

	cout << "Uniform Cost Search : " << endl;
	for(auto ele : ucs)
		cout << ele << " ";

	cout << endl << endl;

	edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1}};

	for(auto edge : edges)
		myGraph4.addEdge(edge[0], edge[1], edge[2]);

	cout << "Node Colors : " << endl;
	vector<int> colors = myGraph4.nodeColoring();

	for(auto ele : colors)
		cout << ele << " ";

	cout << endl << endl;

	Graph<int, int> myGraph5(false);

	adjMat = {{0, 0, 0, 1}, {0, 0, 0, 1}, {1, 1, 1, 0}};

	vector<vector<int>> edges2 = {{0, 1, 1}, {0, 2, 1}, {0, 3, 1}, {4, 0, 1}};
	for(auto edge : edges2)
		myGraph5.addEdge(edge[0], edge[1], edge[2]);

	vector<int> myDFS = myGraph5.iterativeDFS(0);

	cout << "Iterative DFS : " << endl;
	for(auto ele : myDFS)
		cout << ele << " ";

	cout << endl << endl;

	function<double(int, int)> heuristic = [&] (int t1, int t2) -> double
	{
		return 0;
	};

	Graph<int, double> myGraph6(true);

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(adjMat[i][j] == 1)
				myGraph6.addEdge(i, j, random());

	vector<int> ass = myGraph6.aStarSearch(0, 3, heuristic);

	cout << "A Star Search : " << endl;
	for(auto ele : ucs)
		cout << ele << " ";

	cout << endl << endl;
}