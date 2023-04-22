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

	for(int i = 0; i < 5; i++)
		myGraph.addNode(i);

	vector<vector<int>> edges = {{2,1,1},{2,3,1},{3,4,1}};
	for(auto edge : edges)
		myGraph.addEdge(edge[0], edge[1], edge[2]);

	vector<int> temp = myGraph.uniformCostSearch(2, 4);

	for(auto ele : temp)
		cout << ele << " ";
}