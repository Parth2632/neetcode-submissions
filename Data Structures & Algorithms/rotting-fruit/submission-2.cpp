class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(grid[row][col] == 2) {
                    q.push({row, col});
                }
                else if(grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        int minute = 0;

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            while(size--) {

                auto [row, col] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int newRow = row + x[k];
                    int newCol = col + y[k];

                    if(newRow >= 0 && newRow < n &&
                       newCol >= 0 && newCol < m &&
                       grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;
                        fresh--;

                        q.push({newRow, newCol});
                    }
                }
            }

            minute++;
        }

        return fresh == 0 ? minute : -1;
    }
};