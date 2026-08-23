class Solution {
public:

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(vector<vector<int>>& heights, int row, int col) {
        int n = heights.size();
        int m = heights[0].size();

        return row >= 0 && row < n &&
               col >= 0 && col < m;
    }

    void solve(vector<vector<int>>& heights,
               vector<vector<bool>>& visited,
               int row,
               int col) {

        visited[row][col] = true;

        for(int k = 0; k < 4; k++) {

            int newRow = row + x[k];
            int newCol = col + y[k];

            if(valid(heights, newRow, newCol) &&
               !visited[newRow][newCol] &&
               heights[newRow][newCol] >= heights[row][col]) {

                solve(heights, visited, newRow, newCol);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific: top row
        for(int col = 0; col < m; col++) {
            solve(heights, pacific, 0, col);
        }

        // Pacific: left column
        for(int row = 0; row < n; row++) {
            solve(heights, pacific, row, 0);
        }

        // Atlantic: bottom row
        for(int col = 0; col < m; col++) {
            solve(heights, atlantic, n - 1, col);
        }

        // Atlantic: right column
        for(int row = 0; row < n; row++) {
            solve(heights, atlantic, row, m - 1);
        }

        vector<vector<int>> ans;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(pacific[row][col] &&
                   atlantic[row][col]) {

                    ans.push_back({row, col});
                }
            }
        }

        return ans;
    }
};