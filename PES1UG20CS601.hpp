//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "Edge.h"
#include "Cycle.h"
#include "DFS.h"
#include "Components.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Katz.h"
#include "UCS.h"
#include "ASS.h"
#include "Node Coloring.h"
#include "Complete Edges.h"

using namespace std;

template <typename T, typename W>
class Graph
{
private:
	bool directed{};
	set<T> nodeList;
	vector<Edge<T, W>> edgeList;
	map<T, map<T, W>> adjList;

public:
	explicit Graph(bool directed)
	{
		this->directed = directed;
	}

	void addNode(const T& data)
	{
		nodeList.insert(data);
	}

	void addEdge(const T& src, const T& dest, const W& weight)
	{
		if(nodeList.find(src) == nodeList.end())
			nodeList.insert(src);

		if(nodeList.find(dest) == nodeList.end())
			   nodeList.insert(dest);

		edgeList.push_back({src, dest, weight});

		if(directed)
			adjList[src][dest] = weight;

		else
		{
			adjList[src][dest] = weight;
			adjList[dest][src] = weight;
		}
	}

	[[maybe_unused]] [[nodiscard]] bool hasCycle()
	{
		return checkCycle<T, W>(adjList, nodeList, directed);
	}

	vector<vector<T>> connectedComponents()
	{
		return findComponents<T, W>(adjList);
	}

	[[maybe_unused]] vector<T> iterativeDFS(T start)
	{
		return findIterativeDFS(adjList, start);
	}

	[[maybe_unused]] vector<Edge<T, W>> kruskalMST()
	{
		return findKruskal(adjList, edgeList, nodeList.size());
	}

	[[maybe_unused]] vector<Edge<T, W>> primMST()
	 {
		 return findKruskal(adjList, edgeList, nodeList.size());
	 }

	[[maybe_unused]] [[nodiscard]] vector<double> katzCentrality(double alpha, double beta)
	{
		return findKatzCentrality<T, W>(adjList, alpha, beta, nodeList.size());
	}

	[[maybe_unused]] vector<T> uniformCostSearch(T start, T goal)
	{
		return findUCS<T, W>(adjList, start, goal, nodeList.size());
	}

	vector<T> aStarSearch(T start, T goal, std::function<double(T, T)> heuristic)
	{
		return findUCS<T, W>(adjList, start, goal, nodeList.size());;
	}

	vector<int> nodeColoring()
	{
		return findNodeColors<T, W>(adjList, nodeList);
	}

	[[nodiscard]] vector<int> edgeColoring() const
	{
		return findEdgeColors<T, W>(adjList, edgeList);
	}

	void completeEdges()
	{
		findCompleteEdges<T, W>(adjList, edgeList, nodeList);
	}
};