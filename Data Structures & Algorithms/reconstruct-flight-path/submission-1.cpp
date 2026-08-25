class Solution {
public:
    unordered_map<string,vector<string>>adj;
    vector<string>ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets){
            string src = ticket[0];
            string dest = ticket[1];
            adj[src].push_back(dest);
        }
        for(auto &entry: adj){
            sort(entry.second.rbegin(),entry.second.rend());
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(string airport){
        while(!adj[airport].empty()){
            auto node = adj[airport].back();
            adj[airport].pop_back();
            dfs(node);
        }
        ans.push_back(airport);
    }
};
