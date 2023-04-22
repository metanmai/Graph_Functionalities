//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "PES1UG20CS601.hpp"
#include <cmath>

using namespace std;

int main()
{
	Graph<int, int> myGraph(true);

	for(int i = 0; i <= 5; i++)
		myGraph.addNode(i);

//	vector<vector<int>> edges = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
	vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1}};
	for(auto edge : edges)
		myGraph.addEdge(edge[0], edge[1], edge[2]);

	vector<int> temp = myGraph.nodeColoring();

	for(auto ele : temp)
		cout << ele << " ";
}