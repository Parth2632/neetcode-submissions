class Solution {
public:
    vector<vector<string>> res;
    vector<string> diary;

    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return res;
    }

    void solve(string s, int j) {
        // Entire string has been partitioned
        if (j == s.size()) {
            res.push_back(diary);
            return;
        }

        // Try every possible substring starting at j
        for (int i = j; i < s.size(); i++) {

            // substring: s[j ... i]
            if (isPalindrome(s.substr(j, i - j + 1))) {

                diary.push_back(s.substr(j, i - j + 1));

                // Start next partition after i
                solve(s, i + 1);

                // Backtrack
                diary.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};