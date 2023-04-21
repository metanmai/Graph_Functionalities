//
// Created by Tanmai Niranjan on 21/04/23.
//

#ifndef GRAPH_FUNCTIONALITIES_EDGE_H
#define GRAPH_FUNCTIONALITIES_EDGE_H

template <typename T, typename W>
class Edge
{

private:
	T src;
	T dest;
	W weight;
public:
	Edge(const T& src, const T& dest, const W& weight)
	{
		this->src = src;
		this->dest = dest;
		this->weight = weight;
	}

	[[maybe_unused]] T getSource() const
	{
		return this->src;
	}

	[[maybe_unused]] T getDestination() const
	{
		return this->dest;
	}

	[[maybe_unused]] W getWeight() const
	{
		return this->weight;
	}
};


#endif //GRAPH_FUNCTIONALITIES_EDGE_H
