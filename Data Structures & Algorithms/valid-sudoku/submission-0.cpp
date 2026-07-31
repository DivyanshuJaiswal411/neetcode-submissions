class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate Rows
        for (int i = 0; i < 9; i++) {
            vector<int> vis(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                if (vis[val] > 0) return false;
                vis[val]++;
            }
        }

        // Validate Columns
        for (int j = 0; j < 9; j++) {
            vector<int> vis(9, 0);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                if (vis[val] > 0) return false;
                vis[val]++;
            }
        }

        // Validate 3x3 Sub-boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                vector<int> vis(9, 0);
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        char cell = board[boxRow + r][boxCol + c];
                        if (cell == '.') continue;
                        int val = cell - '1';
                        if (vis[val] > 0) return false;
                        vis[val]++;
                    }
                }
            }
        }

        return true;
    }
};