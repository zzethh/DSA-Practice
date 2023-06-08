class Solution {
public:
    bool helper(vector<vector<char>> &board, string word, int i, int j, int m, int n, int s) {
        if (s == word.length() - 1) {
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        bool down = false;
        bool up = false;
        bool right = false;
        bool left = false;
        if (i + 1 < m and board[i + 1][j] == word[s + 1]) {
            down = helper(board, word, i + 1, j, m, n, s + 1);
        }
        if (i - 1 >= 0 and board[i - 1][j] == word[s + 1]) {
            up = helper(board, word, i - 1, j, m, n, s + 1);
        }
        if (j + 1 < n and board[i][j + 1] == word[s + 1]) {
            right = helper(board, word, i, j + 1, m, n, s + 1);
        }
        if (j - 1 >= 0 and board[i][j - 1] == word[s + 1]) {
            left = helper(board, word, i, j - 1, m, n, s + 1);
        }
        board[i][j] = temp;
        if (down or up or right or left) return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, i, j, m, n, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};