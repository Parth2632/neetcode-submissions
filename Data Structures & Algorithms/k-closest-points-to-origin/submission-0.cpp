class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        for(int i=0; i<points.size(); i++){
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({d,points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
