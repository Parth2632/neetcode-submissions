class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    int count = 0;
    bool valid(vector<vector<char>>&grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0){
            return false;
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    solve(grid,i,j);
                }
            }
        }
        return count;
    }
    void solve(vector<vector<char>>&grid,int i, int j){
        if(grid[i][j]=='1'){
            grid[i][j] = '0';
            for(int k=0; k<4; k++){
                int row = x[k];
                int col = y[k];
                if(valid(grid,row+i,col+j)){
                    solve(grid,row+i,col+j);
                }
            }
        }
    }
};
