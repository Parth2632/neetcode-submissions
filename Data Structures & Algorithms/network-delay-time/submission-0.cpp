class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // adjacency list
        vector<vector<pair<int,int>>> adj(n);
        
        for (auto &t : times) {
            int u = t[0] - 1;  // convert to 0-based
            int v = t[1] - 1;
            int w = t[2];
            adj[u].push_back({v, w});
        }

        // min heap (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        pq.push({0, k - 1});

        // Dijkstra
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int node = top.second;

            if (d > dist[node]) continue;

            for (int i = 0; i < adj[node].size(); i++) {
                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;

                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        // find answer using normal loop
        int ans = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};