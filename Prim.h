//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "Edge.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_PRIM_H
#define GRAPH_FUNCTIONALITIES_PRIM_H

template<typename T, typename W>
vector<Edge<T, W>> findPrim(map<T, map<T, W>> &adjList, vector<Edge<T, W>> &edgeList, vector<T> &nodeList)
{
	int n = nodeList.size();
	vector<Edge<T, W>> answer;

	priority_queue<pair<W, pair<T, T>>, vector<pair<W, pair<T, T>>>, greater<>> pq;
	pq.push({0, {-1 , *nodeList.begin()}}); // {weight, {source, destination}};
	set<T> visited;

	while(!pq.empty())
	{
		auto [currWeight, currEdge] = pq.top(); pq.pop();
		auto [source, destination] = currEdge;

		visited.insert(destination);

		if(source != -1)
			answer.push_back({currEdge.first, currEdge.second, currWeight});

		for(auto [nextNode, nextWeight] : adjList[source])
			if(visited.find(nextNode) == visited.end())
				pq.push({nextWeight, {source, nextNode}});
	}

	return answer;
}

#endif //GRAPH_FUNCTIONALITIES_PRIM_H
