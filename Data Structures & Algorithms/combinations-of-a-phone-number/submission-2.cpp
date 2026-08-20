class Solution {
public:
    vector<string> res;
    string diary = "";

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits, 0, mp);

        return res;
    }

    void solve(string &digits, int index, unordered_map<char, string> &mp) {
        // All digits have been processed
        if (index == digits.size()) {
            res.push_back(diary);
            return;
        }

        // Try every possible letter for current digit
        for (char ch : mp[digits[index]]) {
            diary.push_back(ch);

            // Move to next digit
            solve(digits, index + 1, mp);

            // Backtrack
            diary.pop_back();
        }
    }
};