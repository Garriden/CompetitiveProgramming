//https://codeforces.com/contest/1905/problem/B
// Div. 2
// 1000 1100

// Begginer's Zelda

// g++ -o b b.cpp

// greedy
// trees

// Time Limit Exceeded

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const long long MOD = 998244353;

void solve() {
    ll n, m, x, k;
    ll a, b, c, d;
    std::string s;
    ll max = 0;

    std::cin >> n;
    std::vector<bool> visited(/*n+1*/100000, false);
    std::map<ll, std::vector<ll> > neighbours; // key node, value = neighbours.
    ll totalNodes = 0;

    // Build tree (map of neighbours).
    while(totalNodes < n) {
        std::cin >> a >> b;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
        if(!visited[a]) {
            visited[a] = true;
            ++totalNodes;
        }
        if(!visited[b]) {
            visited[b] = true;
            ++totalNodes;
        }
    }
    /*
    for(auto pair : neighbours) {
        std::cout << "node " << pair.first << ":";
        for(int ii = 0; ii < pair.second.size(); ++ii) {
            std::cout << " " << pair.second[ii];
        }
        std::cout << std::endl;
    }
    */

int iindex = 3;
while(neighbours.size() > 1) {
    std::unordered_set<ll> leafs;

    // reset visited vector.
    for(int ii = 0; ii < visited.size(); ++ii) {
        visited[ii] = false;
    }

    // Catch leaves.
    for(auto pair : neighbours) {
        if(pair.second.size() == 1) { // leaf.
            leafs.insert(pair.first);
        }
    }

    std::pair<ll,ll> largestDistanceLeafs = {0, 0};
    std::vector<ll> parent(/*n + 1*/100000, 0);
    int maxDistance = 0;
    // DFS distance for leafs.
    for(auto leaf : leafs) {
        //std::cout << " -- Leaf: " << leaf << std::endl;
        int nextNeighbour = leaf;
        int node = leaf;
        int distance = 0;

        visited[leaf] = true;
        std::stack<ll> st;
        std::stack<int> levels;
        st.push(leaf);
        levels.push(1);

        while(!st.empty()) {
            //std::cout << "Node: " << node << "  / distance: " << distance << std::endl;

            if(distance > maxDistance) {
                maxDistance = distance;
                largestDistanceLeafs.first = leaf;
                largestDistanceLeafs.second = node;
                //std::cout << " distance > maxDistance: " << distance << " " << maxDistance << "  leaf: " << leaf << "  other leaf? " << node << std::endl;
            }

            for(int ii = 0; ii < neighbours[node].size(); ++ii) {
                nextNeighbour = neighbours[node][ii];
                if(!visited[nextNeighbour]) {
                    visited[nextNeighbour] = true;
                    parent[nextNeighbour] = node;
                    st.push(nextNeighbour);
                    levels.push(distance + 1);
                }

            }

            node = st.top(); 
            st.pop();
            distance = levels.top();
            levels.pop();
        }

    }

    //std::cout << "Largests leafes distance: " << largestDistanceLeafs.first  << ", " << largestDistanceLeafs.second << std::endl;


    // Build the largest path.
    std::vector<int> path;
    int current = largestDistanceLeafs.second;
    while(current != -1) {
        path.push_back(current);
        if(current == largestDistanceLeafs.first) break; // Stop when you get back to the start
        current = parent[current];
    }
    std::reverse(path.begin(), path.end());
    //for(int ii = 0; ii < path.size(); ++ii) {
    //    std::cout << path[ii] << " ";
    //} std::cout << std::endl;

    // reset visited vector.
    for(int ii = 0; ii < visited.size(); ++ii) {
        visited[ii] = false;
    }
    for(int ii = 0; ii < path.size(); ++ii) {
        visited[path[ii]] = true;
    }

    ++totalNodes;
    // Erase all nodes between those two leaves.
    for(int ii = 0; ii < path.size(); ++ii) {
        int node = path[ii];
        visited[node] = true;
        for(int jj = 0; jj < neighbours[node].size(); ++jj) {
            int possibleNode = neighbours[node][jj];
            if(!visited[possibleNode]) {
                neighbours[totalNodes].push_back(possibleNode);
            }
        }
    }

    for(int ii = 0; ii < path.size(); ++ii) {
        neighbours.erase(path[ii]);
    }

    // restructure neighbours.
    for(auto &pair : neighbours) {
        int node = pair.first;
        if(node != totalNodes) {
            for(int ii = 0; ii < pair.second.size(); ++ii) {
                for(int jj = 0; jj < path.size(); ++jj) {
                    if(pair.second[ii] == path[jj]) {
                        //std::cout << "Erase node: " << pair.second[ii] << std::endl;
                        pair.second.erase(pair.second.begin() + ii);
                        break;
                    }
                }
            }
            neighbours[node].push_back(totalNodes);
        }
    }
    //for(auto pair : neighbours) {
    //    std::cout << "node " << pair.first << ":";
    //    for(int ii = 0; ii < pair.second.size(); ++ii) {
    //        std::cout << " " << pair.second[ii];
    //    }
    //    std::cout << std::endl;
    //}

    //std::cout << "    neighbours.sise: " << neighbours.size() << std::endl << std::endl;


    ++max;
}

    //std::cout << "max: " << max << std::endl;
    std::cout << max << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}
