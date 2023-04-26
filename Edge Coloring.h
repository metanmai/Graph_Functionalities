//
// Created by Tanmai Niranjan on 22/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "Edge.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_EDGE_COLORING_H
#define GRAPH_FUNCTIONALITIES_EDGE_COLORING_H

template<typename T, typename W>
vector<int> EdgeColoring(map<T, map<T, W>> &adjList, vector<Edge<T, W>> &edgeList)
{
	vector<int> answer(edgeList.size(), -1);
	vector<set<int>> cantBe(edgeList.size());
	queue<int> q;
	q.push(0);

	while(!q.empty())
	{
		auto curr = q.front(); q.pop();
	}
}

#endif //GRAPH_FUNCTIONALITIES_EDGE_COLORING_H
