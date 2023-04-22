//
// Created by Tanmai Niranjan on 22/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_NODE_COLORING_H
#define GRAPH_FUNCTIONALITIES_NODE_COLORING_H

template<typename T, typename W>
vector<T> findNodeColors(map<T, map<T, W>> &adjList, set<int> &nodeList)
{
	vector<T> answer(nodeList.size(), -1);
	vector<set<T>> cantBe(nodeList.size());
	queue<pair<T, W>> q;
	answer[0] = 0;

	q.push({*nodeList.begin(), 0});

	while(!q.empty())
	{
		auto ele = q.front(); q.pop();
		auto currNode = ele.first, currColor = ele.second;

		for(auto [nextNode, _] : adjList[currNode])
		{
			cantBe[nextNode].insert(currColor);
			int nextColor = 0;

			while(cantBe[nextNode].find(nextColor) != cantBe[nextNode].end())
				nextColor++;

			q.push({nextNode, answer[nextNode] = nextColor});
		}
	}

	for(auto node : nodeList)
		answer[node] = answer[node] == -1 ? 0 : answer[node];

	return answer;
}

#endif //GRAPH_FUNCTIONALITIES_NODE_COLORING_H
