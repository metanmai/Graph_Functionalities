//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"
#include "Edge.h"
#include "Cycle.h"
#include "DFS.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Katz.h"

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
		try
		{
			if(nodeList.find(src) == nodeList.end() or
			   nodeList.find(dest) == nodeList.end())
				throw(100);
		}

		catch(int errCode)
		{
			cout << "Error code : " << errCode << endl;
			cout << "Invalid Edge!" << endl;
		}

		edgeList.push_back({src, dest, weight});

		if(directed)
			adjList[src][dest] = weight;

		else
		{
			adjList[src][dest] = weight;
			adjList[dest][src] = weight;
		}
	}

	[[maybe_unused]] [[nodiscard]] bool hasCycle() // Complete
	{
		return checkCycle<T, W>(adjList, nodeList, directed);
	}

	[[maybe_unused]] std::vector<T> iterativeDFS(T start) // Complete
	{
		return findIterativeDFS(adjList, start);
	}

	[[maybe_unused]] std::vector<Edge<T, W>> kruskalMST() const
	{
		return findKruskal(adjList, edgeList, nodeList.size());
	}

	[[maybe_unused]] std::vector<Edge<T, W>> primMST() const
	 {
		 return findPrim(adjList, edgeList, nodeList);
	 }

	[[maybe_unused]] [[nodiscard]] std::vector<double> katzCentrality(double alpha, double beta)
	{
		return findKatzCentrality<T, W>(adjList, alpha, beta, nodeList.size());
	}

	[[maybe_unused]] std::vector<T> uniformCostSearch(const T& start, const T& goal) const
	{
		vector<T> answer;

		priority_queue<pair<int, int>> pq;

	}



	// Algorithm implementations
	std::vector<int> nodeColoring() const;
	std::vector<int> edgeColoring() const;
	void completeEdges();
	std::vector<std::vector<T>> connectedComponents() const;

//	[[maybe_unused]] std::vector<T> uniformCostSearch(const T& start, const T& goal) const;
	std::vector<T> aStarSearch(const T& start, const T& goal, std::function<double(T, T)> heuristic)
	const;
};