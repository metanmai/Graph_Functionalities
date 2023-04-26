//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "PES1UG20CS601.hpp"
#include "Edge.h"

using namespace std;

int main()
{
	Graph<int, int> myGraph(true);

	for(int i = 0; i < 5; i++)
		myGraph.addNode(i);

//	vector<vector<int>> edges = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
//	vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1}};
//	vector<vector<int>> edges = {{0, 1, 1},
//								 {1, 2, 1},
//								 {3, 4, 1}};
	vector<vector<int>> adjMat = {{0,1,1,1,0},
								  {1,0,1,1,1},
								  {1,1,0,1,1},
								  {1,1,1,0,0},
								  {0,1,1,0,0}};

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(adjMat[i][j] == 1)
				myGraph.addEdge(i, j, 1);
//
//	for(auto edge : edges)
//		myGraph.addEdge(edge[0], edge[1], edge[2]);

//	vector<vector<int>> comps = myGraph.connectedComponents();
	vector<double> temp = myGraph.katzCentrality(0.25, 0.2);

	for(auto ele : temp)
		cout << ele << " ";

	cout << endl;

	myGraph.completeEdges();
}