class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Construct graph
        for(auto prerequisite : prerequisites){
            int course = prerequisite[0];
            int prereq = prerequisite[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Courses with no prerequisites
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            count++;

            for(int neigh : adj[node]){
                indegree[neigh]--;

                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return count == numCourses;
    }
};