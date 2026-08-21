class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    int ans = 0;
    bool valid(vector<vector<int>>&grid,int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || row>=n || col<0 || col>=m){
            return false;
        }
        return true;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int area = solve(grid,i,j);
                    ans = max(area,ans);
                }
            }            
        }
        return ans;
    }
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (!valid(grid, i, j) || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int area = 1;
        for(int k = 0; k < 4; k++){
            int row = i + x[k];
            int col = j + y[k];
            area += solve(grid, row, col);
        }
        return area;
    }
};
