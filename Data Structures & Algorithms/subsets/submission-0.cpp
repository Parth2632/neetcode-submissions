class Solution {
public:
    vector<vector<int>>res;
    vector<int>diary;
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return res;
    }
    void solve(vector<int>&nums,int i){
        if(i==nums.size()){
            res.push_back(diary);
            return;
        }
        diary.push_back(nums[i]); //take the element
        solve(nums,i+1); //move forward


        diary.pop_back(); //move backwards 

        solve(nums,i+1); //move forward again
    }
};
