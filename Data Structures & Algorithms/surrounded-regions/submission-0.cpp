class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(vector<vector<char>>& board, int row, int col) {
        int n = board.size();
        int m = board[0].size();

        return row >= 0 && row < n &&
               col >= 0 && col < m;
    }

    void func(vector<vector<char>>& board, int row, int col) {

        board[row][col] = '#';

        for(int k = 0; k < 4; k++) {

            int newRow = row + x[k];
            int newCol = col + y[k];

            if(valid(board, newRow, newCol) &&
               board[newRow][newCol] == 'O') {

                func(board, newRow, newCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // Left and right boundaries
        for(int row = 0; row < n; row++) {

            if(board[row][0] == 'O')
                func(board, row, 0);

            if(board[row][m - 1] == 'O')
                func(board, row, m - 1);
        }

        // Top and bottom boundaries
        for(int col = 0; col < m; col++) {

            if(board[0][col] == 'O')
                func(board, 0, col);

            if(board[n - 1][col] == 'O')
                func(board, n - 1, col);
        }

        // Convert surrounded O -> X
        // Convert safe # -> O
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(board[row][col] == 'O')
                    board[row][col] = 'X';

                else if(board[row][col] == '#')
                    board[row][col] = 'O';
            }
        }
    }
};