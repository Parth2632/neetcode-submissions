class Solution {
public:
    vector<vector<int>> res;
    vector<int> diary;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        solve(nums, used);
        return res;
    }

    void solve(vector<int>& nums, vector<bool>& used) {

        if(diary.size() == nums.size()) {
            res.push_back(diary);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i])
                continue;

            used[i] = true;
            diary.push_back(nums[i]);

            solve(nums, used);

            diary.pop_back();
            used[i] = false;
        }
    }
};
