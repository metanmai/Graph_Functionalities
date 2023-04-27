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
double findJaccard(map<T, map<T, W>> &adjList, T node1, T node2)
{
	vector<T> v1, v2, v3;
	for(auto [nextNode, _] : adjList[node1])
		v1.push_back(nextNode);

	for(auto [nextNode, _] : adjList[node2])
		v2.push_back(nextNode);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

	return (v3.size()) / (double) (v1.size() + v2.size() - v3.size());
}

/* Find Jaccard Similarity between all pairs of nodes,
 * and find the nodes with the most similarity and create an edge between them. */
template<typename T, typename W>
void findCompleteEdges(map<T, map<T, W>> &adjList, vector<Edge<T, W>> &edgeList, set<T> &nodeList)
{
	int n = nodeList.size(), maxJaccard = 0, node1 = 0, node2 = 1;
	vector<T> nodes = vector(nodeList.begin(), nodeList.end());

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			int currJaccard = findJaccard<T, W>(adjList, nodes[i], nodes[j]);

			if(currJaccard > maxJaccard)
			{
				if(!edgeExists(adjList, nodes[i], nodes[j]))
					maxJaccard = currJaccard, node1 = nodes[i], node2 = nodes[j];

				else if(!edgeExists(adjList, nodes[j], nodes[i]))
					maxJaccard = currJaccard, node1 = nodes[j], node2 = nodes[i];
			}
		}

	auto weight = findWeight<T, W> (adjList, node1, node2);
	adjList[node1][node2] = weight;
	edgeList.push_back({node1, node2, weight});
//
	cout << "An Edge has been created from " << node1 << " to " << node2 << " with weight " << weight << endl;
}

#endif //GRAPH_FUNCTIONALITIES_COMPLETE_EDGES_H
