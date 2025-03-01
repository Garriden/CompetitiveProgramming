#include <iostream>
#include <queue>
#include "NodeGraph.hpp"

// g++ .\0104RouteBetweenNodes.cpp NodeGraph.cpp -o hola

/*
    BFS
*/

bool visited(std::vector<NodeGraph*> v, const int &n1, const int &n2)
{
    std::queue<int> qu;
    std::vector<bool> visited(v.size(), false);

    qu.push(n1);

    while(!qu.empty()) {
        int value = qu.front();
        //std::cout << "node: " << value << std::endl;
        if(value == n2) {
            return true;
        } else {
            visited[value-1] = true;
            for(int ii = 0; ii < v[value-1]->adjacent.size(); ++ii) {
                if(!visited[ v[value-1]->adjacent[ii] -1]) {
                    qu.push(v[value-1]->adjacent[ii]);
                    //std::cout << "  push: " << v[value-1]->adjacent[ii] << std::endl;
                }
            }
        }

        qu.pop();

    }

    return false;
}



int main()
{
    // Build a graph
    Graph g;
    g.CreateGraph({ {1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 6}, {2, 3}, {6, 2}, {6, 5}, {6, 4}/*, {7, 8}, {6, 7} */ });
    g.PrintGraph();

    std::cout << visited(g.nodes, 1, 5) << std::endl;
    std::cout << visited(g.nodes, 5, 1) << std::endl;

    return 0;
}