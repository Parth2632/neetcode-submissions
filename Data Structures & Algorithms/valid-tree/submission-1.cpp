class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for(int neigh : adj[node]) {
            if(neigh == parent)
                continue;

            if(visited[neigh])
                return false;

            if(!dfs(neigh, node, adj, visited))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        if(!dfs(0, -1, adj, visited))
            return false;

        for(bool x : visited) {
            if(!x)
                return false;
        }

        return true;
    }
};