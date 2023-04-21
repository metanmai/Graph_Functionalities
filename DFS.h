//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_DFS_H
#define GRAPH_FUNCTIONALITIES_DFS_H

template<typename T, typename W>
vector<T> findIterativeDFS(map<T, map<T, W>> &adjList, T& start)
{
	stack<T> st;
	unordered_set<T> visited;

	st.push(start);

	while(!st.empty())
	{
		auto curr = st.top(); st.pop();

		if(visited.find(curr) != visited.end())
			continue;

		visited.insert(curr);

		for(auto [node, _] : adjList[curr])
			st.push(node);
	}

	vector<T> answer = vector(visited.begin(), visited.end());
	reverse(answer.begin(), answer.end());

	return answer;
}

#endif //GRAPH_FUNCTIONALITIES_DFS_H
