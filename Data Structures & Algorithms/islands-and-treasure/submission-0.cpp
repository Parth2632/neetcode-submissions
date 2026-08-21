class Solution {
public:

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int row = i + x[k];
                int col = j + y[k];

                if(valid(grid, row, col) &&
                   grid[row][col] == 2147483647) {

                    grid[row][col] = grid[i][j] + 1;

                    q.push({row, col});
                }
            }
        }
    }
};