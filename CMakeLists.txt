cmake_minimum_required(VERSION 3.25)
project(Graph_Functionalities)

set(CMAKE_CXX_STANDARD 23)

add_executable(Graph_Functionalities main.cpp "PES1UG20CS601.hpp" DisjointSet.h Katz.h DFS.h Kruskal.h Edge.h Components.h Cycle.h Prim.h UCS.h "Node Coloring.h" "Edge Coloring.h" ASS.h "Complete Edges.h")
