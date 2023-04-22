//
// Created by Tanmai Niranjan on 22/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_UCS_H
#define GRAPH_FUNCTIONALITIES_UCS_H

template<typename T, typename W>
vector<T> findUCS(map<T, map<T, W>> &adjList, T &start, T &goal, int n)
{
	vector<T> answer(n, INT_MAX);
	answer[start] = 0;
	priority_queue<pair<W, T>, vector<pair<W, T>>, greater<>> pq;
	pq.push({0, start});

	while(!pq.empty())
	{
		auto [currWeight, currNode] = pq.top(); pq.pop();

		for(auto [nextNode, nextWeight] : adjList[currNode])
			if(currWeight + nextWeight < answer[nextNode])
				pq.push({answer[nextNode] = currWeight + nextWeight, nextNode});
	}

	for(int &num : answer)
		num = num == INT_MAX ? -1 : num;

	return answer;

}

#endif //GRAPH_FUNCTIONALITIES_UCS_H
