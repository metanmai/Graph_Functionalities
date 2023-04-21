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

	myGraph.addEdge(0, 1, random());
	myGraph.addEdge(1, 2, random());
	myGraph.addEdge(2, 3, random());
	myGraph.addEdge(3, 4, random());
	myGraph.addEdge(4, 0, random());

	vector<double> temp = myGraph.katzCentrality(0.5587, 0.421);

	for(auto ele : temp)
		cout << ele << " ";
}