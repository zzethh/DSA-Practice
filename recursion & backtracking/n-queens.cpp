class Solution {
public:
    vector<vector<string>> str;
    void display(bool board[1000][1000], int row, int col) {
        vector<string> v;
        for (int i = 0; i < row; i++) {
            string s = "";
            for (int j = 0; j < col; j++) {
                if (board[i][j]) {
                    s += "Q";
                    //cout << " Q ";
                } else {
                    s += ".";
                    // cout << " - ";
                }
            }
            v.push_back(s);
            cout << endl;
        }
        str.push_back(v);
    }

    bool isSafe(bool board[1000][1000], int row, int col, int r, int c) {
        //vertical row
        for (int i = 0; i < r; i++) {
            if (board[i][c]) {
                return false;
            }
        }

        //left diagonal
        int maxLeft = min(r, c);
        for (int i = 1; i <= maxLeft; i++) {
            if (board[r - i][c - i]) {
                return false;
            }
        }

        //right diagonal
        int maxRight = min(r, col - c - 1);
        for (int i = 1; i <= maxRight; i++) {
            if (board[r - i][c + i]) {
                return false;
            }
        }

        return true;

    }

    int Nqueens(bool board[1000][1000], int row, int col, int r) {
        if (r == row) {
            display(board, row, col);
            cout << endl;
            return 1;
        }

        int cnt = 0;

        for (int column = 0; column < col; column++) {
            if (isSafe(board, row, col, r, column)) {
                board[r][column] = true;
                cnt = cnt + Nqueens(board, row, col, r + 1);
                board[r][column] = false;
            }
        }

        return cnt;
    }
    vector<vector<string>> solveNQueens(int n) {
        bool board[1000][1000];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = false;
            }
        }
        Nqueens(board, n, n, 0);
        return str;
    }
};