class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto prerequisite: prerequisites){
            int src = prerequisite[1];
            int dest = prerequisite[0];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            count++;
            q.pop();
            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(count==numCourses){
            return ans;
        }
        else{
            return {};
        }
    }
};
