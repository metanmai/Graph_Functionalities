//
// Created by Tanmai Niranjan on 21/04/23.
//

#include <vector>

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_DISJOINTSET_H
#define GRAPH_FUNCTIONALITIES_DISJOINTSET_H

template<typename T>
class DisjointSet
{
private:
	map<T, T> parent, rank;

public:
	explicit DisjointSet(int n)
	{
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	T findParent(T node)
	{
		if(node == parent[node])
			return node;

		return parent[node] = findParent(parent[node]);
	}

	bool unionBySize(T node1, T node2)
	{
		T par1 = findParent(node1), par2 = findParent(node2);

		if(par1 == par2)
			return false;

		if(rank[par1] < rank[par2])
		{
			parent[par1] = par2;
			rank[par2] += rank[par1];
		}

		else
		{
			parent[par2] = par1;
			rank[par1] += rank[par2];
		}

		return true;
	}
};
#endif //GRAPH_FUNCTIONALITIES_DISJOINTSET_H
