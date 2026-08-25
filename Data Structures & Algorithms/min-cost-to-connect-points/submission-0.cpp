class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // visited[i] tells whether point i is already included in MST
        vector<int> visited(n, 0);


        // min heap stores:
        // {cost to connect, point index}
        priority_queue<pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;


        // Start from point 0 with cost 0
        pq.push({0, 0});


        int totalCost = 0;
        int count = 0;


        while(!pq.empty()){


            // Pick the cheapest edge available
            auto [cost, node] = pq.top();
            pq.pop();


            // If already included, skip
            if(visited[node])
                continue;


            // Add this point to MST
            visited[node] = 1;

            totalCost += cost;

            count++;


            // Add all possible connections from this point
            for(int next = 0; next < n; next++){

                if(!visited[next]){

                    // Manhattan distance
                    int distance = 
                    abs(points[node][0] - points[next][0]) +
                    abs(points[node][1] - points[next][1]);


                    // Add this possible edge
                    pq.push({distance, next});
                }
            }
        }


        return totalCost;
    }
};