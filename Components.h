//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_COMPONENTS_H
#define GRAPH_FUNCTIONALITIES_COMPONENTS_H

template<typename T, typename W>
void findNodesInComponent(map<T, map<T, W>> &adjList, T currNode,
						  set<T> &visited, vector<T> &component)
{
	if(visited.find(currNode) != visited.end())
		return;

	visited.insert(currNode);
	component.push_back(currNode);

	for(auto [nextNode, _] : adjList[currNode])
		findNodesInComponent(adjList, nextNode, visited, component);
}

template<typename T, typename W>
vector<vector<T>> findComponents(map<T, map<T, W>> &adjList)
{
	vector<vector<T>> components;
	set<T> visited;

	for(auto [currNode, _] : adjList)
	{
		if(visited.find(currNode) != visited.end())
			continue;

		vector<T> component;
		findNodesInComponent(adjList, currNode, visited, component);
		components.push_back(component);
	}

	return components;
}

#endif //GRAPH_FUNCTIONALITIES_COMPONENTS_H
