class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node] = true;
        for(auto neigh: adj[node]){
            if(!visited[neigh]){
                dfs(neigh,adj,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge: edges){
            int src = edge[0];
            int dest = edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<bool>visited(n,false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};
