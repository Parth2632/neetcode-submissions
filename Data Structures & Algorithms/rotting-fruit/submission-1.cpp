class Solution {
public:
    queue<pair<int,int>>q;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    int minute = 0;
    bool valid(vector<vector<int>>&grid,int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh > 0){
            int size = q.size();
            while(size--){
                auto [i,j] = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                int row = x[k] + i;
                int col = y[k] + j;
                    if(valid(grid,row,col) && grid[row][col]==1){
                        fresh--;
                        grid[row][col]=2;
                        q.push({row,col});
                    }
                }
            }
            minute++;
        }
        if(fresh>0){
            return -1;
        }
        return minute;
    }
};
