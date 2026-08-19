class Solution {
public:
    vector<int>diary;
    vector<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return res;
    }
    void solve(vector<int>&nums,int idx){   
        res.push_back(diary);
        
        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i]==nums[i-1]){
                continue;
            }
            diary.push_back(nums[i]);
            solve(nums,i+1);
            diary.pop_back();
        }
        return;
    }
};
