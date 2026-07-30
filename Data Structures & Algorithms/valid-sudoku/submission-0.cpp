class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,int>>rows(9);
        vector<unordered_map<char,int>>cols(9);
        vector<unordered_map<char,int>> boxes(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                char nums = board[i][j];
                rows[i][nums]++;
                cols[j][nums]++;
                int boxrow = i/3;
                int boxcol = j/3;
                int boxIndex = boxrow * 3 + boxcol;
                boxes[boxIndex][nums]++;
                if(rows[i][nums]>1 || cols[j][nums]>1 || boxes[boxIndex][nums]>1 ){
                    return false;
                }
            }
        }
        return true;
    }
};