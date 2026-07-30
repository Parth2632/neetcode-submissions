class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>>p;
        for(auto &i: freq){
            p.push_back({i.first,i.second});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(int i=0; i<k;i++){
            pq.push({p[i].second,p[i].first}); //frequency then value
        }
        for(int i=k;i<p.size();i++){
            auto a = pq.top();
            if(p[i].second>a.first){
                pq.pop();
                pq.push({p[i].second,p[i].first});
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            int q = pq.top().second;
            pq.pop();
            ans.push_back(q);
        }
        return ans;
    }
};
