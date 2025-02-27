
#include "NodeGraph.hpp"
#include <iostream>

NodeGraph::NodeGraph() : value{0}, adjacent{}  {}

NodeGraph::NodeGraph(int val) : value{val}, adjacent{} {}

void NodeGraph::AddNeighbour(int value)
{
    adjacent.push_back(value);
}


Graph::Graph() {}

void Graph::CreateGraph(std::vector<std::pair<int, int> > v)
{
    for(int ii = 0; ii < v.size(); ++ii) {
        NodeGraph* n;
        int vectorPos = v[ii].first-1;

        if(nodes.size() > vectorPos) { // Exist
            n = nodes[vectorPos];
            n->AddNeighbour(v[ii].second);
        } else {
            n = new NodeGraph(v[ii].first);
            n->AddNeighbour(v[ii].second);
            nodes.push_back(n);
        }
        
    }
}

void Graph::PrintGraph()
{
    for(auto node : nodes) {
        std::cout << "|" << node->value << "|" << " -> ";
        for(int jj = 0; jj < node->adjacent.size(); ++jj) {
            std::cout << node->adjacent[jj] << " -> ";
        }
        std::cout << std::endl;
    }
    
}
