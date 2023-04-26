//
// Created by Tanmai Niranjan on 26/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "Edge.h"
#include "Katz.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_COMPLETE_EDGES_H
#define GRAPH_FUNCTIONALITIES_COMPLETE_EDGES_H

template<typename T, typename W>
bool edgeExists(map<T, map<T, W>> &adjList, int node1, int node2)
{
	return (adjList[node1].find(node2) != adjList[node1].end());
}

template<typename T, typename W>
W findWeight(map<T, map<T, W>> &adjList, int node1, int node2)
{
	int degree1 = adjList[node1].size(), degree2 = adjList[node2].size();
	T weights1 = 0, weights2 = 0;

	for(auto [_, weight] : adjList[node1])
		weights1 += weight;

	for(auto [_, weight] : adjList[node2])
		weights2 += weight;

	T avgWeight1 = (T) weights1 / degree1, avgWeight2 = (T) weights2 / degree2;

	return (avgWeight1 * degree1 + avgWeight2 * degree2) / (degree1 + degree2);
}

template<typename T, typename W>
void findCompleteEdges(map<T, map<T, W>> &adjList, vector<Edge<T, W>> &edgeList, int n)
{
	vector<double> centralities = findKatzCentrality(adjList, 0.25, 0.2);
	vector<pair<double, int>> sortedCentralities(n);

	for(int i = 0; i < n; i++)
		sortedCentralities[i] = {centralities[i], i};

	sort(centralities.begin(), centralities.end(), greater<> ());

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			int node1 = i, node2 = j;

			if(edgeExists<T, W>(adjList, i, j) or
			   edgeExists<T, W>(adjList, j, i))
				continue;

			else if(edgeExists<T, W>(adjList, i, j) and
			        !edgeExists<T, W>(adjList, j, i))
				swap(node1, node2);

			auto weight = findWeight<T, W> (adjList, i, j);
			adjList[node1][node2] = weight;
			edgeList.push_back({node1, node2, weight});

			cout << "An Edge has been created between " << node1 << "and " << node2 << endl;
			return;
		}
}

#endif //GRAPH_FUNCTIONALITIES_COMPLETE_EDGES_H
