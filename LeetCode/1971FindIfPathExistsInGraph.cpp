    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(int kk = 0; kk < edges.size(); ++kk) {
            int index = edges[kk][0];
            int jndex = edges[kk][1];

            graph[index].push_back(jndex);
            graph[jndex].push_back(index);
            
        }

        vector<bool> seen(n);
        seen[source] = true;

        queue<int> qu;
        qu.push(source);

        while(!qu.empty()) {
            int x = qu.front();
            if(x == destination) return true;
            qu.pop();

            //for (int ii : graph[x]) {
            for (int ii = 0; ii < graph[x].size(); ++ii) {
                int element = graph[x][ii];
                if(!seen[element]) {
                    seen[element] = true;
                    qu.push(element);
                }
            }

        }

        return false;
    }
