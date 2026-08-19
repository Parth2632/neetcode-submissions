class Solution {
public:
    vector<vector<int>> res;
    vector<int> diary;

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return res;
    }

    void solve(vector<int>& nums,int i){

        if(i == nums.size()){
            res.push_back(diary);
            return;
        }

        // take
        diary.push_back(nums[i]);
        solve(nums,i+1);

        // undo
        diary.pop_back();

        // don't take
        solve(nums,i+1);
    }
};
