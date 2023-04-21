//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "Edge.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_CYCLE_H
#define GRAPH_FUNCTIONALITIES_CYCLE_H

template<typename T, typename W>
bool checkCycle(map<T, map<T, W>> &adjList,
				set<T> &nodeList, bool directed)
{
	set<T> visited;
	queue<pair<T, T>> q;

	q.push({*nodeList.begin(), -1}); // {curr, prev}.

	while(!q.empty())
	{
		auto [curr, prev] = q.front(); q.pop();

		if(visited.find(curr) != visited.end())
			return true;

		visited.insert(curr);

		for(auto [next, _] : adjList[curr])
			if(next != prev)
				q.push({next, curr});

			else if(directed)
				return true;
	}

	return false;
}

#endif //GRAPH_FUNCTIONALITIES_CYCLE_H
