class Solution {
public:
    vector<vector<string>>res;
    vector<string>diary;
    bool isValid(int n,int i,int j){
        if(i==0 && j==0){
            return true;
        }
        for(int row=i-1;row>=0;row--){
            if(diary[row][j]=='Q'){
                return false;
            }
        }
        for(int row=i-1,col=j-1;row>=0 && col>=0; row--,col--){
            if(diary[row][col]=='Q'){
                return false;
            }
        }
        for(int row=i-1,col=j+1;row>=0 && col<n; row--,col++){
            if(diary[row][col]=='Q'){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        diary = vector<string>(n,string(n,'.'));
        solve(n,0);
        return res;
    }
    void solve(int n,int i){
        if(i==n){
            res.push_back(diary);
            return;
        }
        for(int j=0;j<n;j++){
            if(isValid(n,i,j)){
                diary[i][j]='Q';
                solve(n,i+1);
                diary[i][j] = '.';
            }
        }
    }
};