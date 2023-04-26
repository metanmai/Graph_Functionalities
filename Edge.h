//
// Created by Tanmai Niranjan on 21/04/23.
//

#ifndef GRAPH_FUNCTIONALITIES_EDGE_H
#define GRAPH_FUNCTIONALITIES_EDGE_H

template <typename T, typename W>
class Edge
{
public:
	T src, dest;
	W weight;

	Edge(const T& src, const T& dest, const W& weight)
	{
		this->src = src;
		this->dest = dest;
		this->weight = weight;
	}
};


#endif //GRAPH_FUNCTIONALITIES_EDGE_H
