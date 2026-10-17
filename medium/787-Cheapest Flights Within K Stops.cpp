class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Creating an adjacency list
        
        vector<pair<int, int>> graph[n]; // graph[u] = {v, wt}

        for(int i=0; i<flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        // Modified BFS

        vector<int> dist(n, INT_MAX);
        queue<pair<int, pair<int, int>>> Q; // {dest, {wt, stops}}

        dist[src] = 0;
        Q.push({src, {0, -1}});

        while(Q.size() > 0) {
            auto val = Q.front();
            int u = val.first;
            int cost = val.second.first;
            int stops = val.second.second;

            Q.pop();

            for(auto edge : graph[u]) {
                int v = edge.first;
                int wt = edge.second;

                if(dist[v] > wt + cost && stops + 1 <= k) {
                    dist[v] = wt + cost;
                    Q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};