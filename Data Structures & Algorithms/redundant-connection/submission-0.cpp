class Solution {
public:
    vector<int> parent, rank;

    int findparent(int u) {
        if(u == parent[u])
            return u;

        return parent[u] = findparent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int u_par = findparent(u);
        int v_par = findparent(v);

        if(u_par == v_par)
            return;

        if(rank[u_par] < rank[v_par]) {
            parent[u_par] = v_par;
        }
        else if(rank[v_par] < rank[u_par]) {
            parent[v_par] = u_par;
        }
        else {
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if(findparent(u) == findparent(v))
                return edge;

            unionByRank(u, v);
        }

        return {};
    }
};