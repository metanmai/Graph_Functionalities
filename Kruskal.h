//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "Edge.h"
#include "DisjointSet.h"

#define ff first
#define ss second

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_KRUSKAL_H
#define GRAPH_FUNCTIONALITIES_KRUSKAL_H

template<typename T, typename W>
vector<Edge<T, W>> findKruskal(map<T, map<T, W>> &adjList, vector<Edge<T, W>> &edgeList, int n)
{
	vector<Edge<T, W>> answer;
	DisjointSet<T> ds(n);

	priority_queue<pair<W, pair<T, T>>, vector<pair<W, pair<T, T>>>, greater <>> pq; // {weight, {node1, node2}}.

	for(auto edge : edgeList)
		pq.push({edge.weight, {edge.src, edge.dest}});

	while(!pq.empty())
	{
		auto top = pq.top(); pq.pop();

		if(ds.unionBySize(top.ss.ff, top.ss.ss))
			answer.push_back({top.ss.ff, top.ss.ss, top.ff});
	}

	return answer;
}

#endif //GRAPH_FUNCTIONALITIES_KRUSKAL_H
