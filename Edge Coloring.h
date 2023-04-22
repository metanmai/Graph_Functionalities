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
	vector<set<

}

#endif //GRAPH_FUNCTIONALITIES_EDGE_COLORING_H
