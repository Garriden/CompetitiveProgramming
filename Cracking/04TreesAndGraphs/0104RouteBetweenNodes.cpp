#include <iostream>
#include "NodeGraph.hpp"

// g++ .\0104RouteBetweenNodes.cpp NodeGraph.cpp -o hola

/*

*/

int main()
{
    // Build a graph
    Graph g;
    g.CreateGraph({ {1, 2}, {2, 1}, {3, 1}, {4, 0}, {5, 1}, {1, 5}, {2, 3}, {6, 1}, {1, 7}});
    g.PrintGraph();

    std::cout << std::endl;

    return 0;
}