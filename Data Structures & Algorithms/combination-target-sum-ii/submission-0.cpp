class Solution {
public:
    vector<vector<int>> res;
    vector<int> diary;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target);
        return res;
    }

    void solve(vector<int>& candidates, int start, int target) {

        if(target == 0) {
            res.push_back(diary);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            if(i > start && candidates[i] == candidates[i - 1])
                continue;

            if(candidates[i] > target)
                break;

            diary.push_back(candidates[i]);

            solve(candidates, i + 1, target - candidates[i]);

            diary.pop_back();
        }
    }
};