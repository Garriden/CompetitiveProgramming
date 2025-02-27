#ifndef NODE_GRAPH_H
#define NODE_GRAPH_H

#include <vector>
#include <unordered_set>

class NodeGraph {
public:
    NodeGraph();
    NodeGraph(int val);

    ~NodeGraph() {}

    void AddNeighbour(int value);

    int value;
    std::vector<int> adjacent;
};


class Graph {
public:
    Graph();

    void CreateGraph(std::vector<std::pair<int, int> > v);

    void PrintGraph();

    std::vector<NodeGraph*> nodes;
};


#endif