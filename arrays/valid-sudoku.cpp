class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int m, int n, int r, int c) {
        int num = board[r][c] - '0';
        for (int i = 0; i < m; i++) {
            int n = board[i][c] - '0';
            if (i == r) continue;
            if (n == num) return false;
        }
        for (int j = 0; j < n; j++) {
            int n = board[r][j] - '0';
            if (j == c) continue;
            if (n == num) return false;
        }
        int rowStart = (r / 3) * 3;
        int colStart = (c / 3) * 3;
        for (int i = rowStart; i < rowStart + 3; i++) {
            for (int j = colStart; j < colStart + 3; j++) {
                if (i == r and j == c) continue;
                int n = board[i][j] - '0';
                if (n == num) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                bool f = isSafe(board, board.size(), board[0].size(), i, j);
                if (!f) return false;
            }
        }
        return true;
    }
};