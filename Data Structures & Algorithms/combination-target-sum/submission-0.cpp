class Solution {
public:
    vector<vector<int>>res;
    vector<int>diary;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums,target,0,0);
        return res;
    }
    void solve(vector<int>&nums,int target, int sum, int i){
        if(sum==target){
            res.push_back(diary);
            return;
        }
        if(sum>target || i==nums.size()){
            return;
        }
        diary.push_back(nums[i]);
        solve(nums,target,sum+nums[i],i);
        diary.pop_back();

        solve(nums,target,sum,i+1);
    }
};
