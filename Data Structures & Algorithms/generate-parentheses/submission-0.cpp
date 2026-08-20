class Solution {
public:
    string diary;
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        solve(n,0,0);
        return res;
    }
    void solve(int n,int open,int close){
        if(open==n && close==n){
            res.push_back(diary);
            return;
        }
        if(open<n){
            diary.push_back('(');
            solve(n,open+1,close);
            diary.pop_back();
        }
        if(close<open){
            diary.push_back(')');
            solve(n,open,close+1);
            diary.pop_back();
        }
    }
};
