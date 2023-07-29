class Solution {
public:
    // void display(int board[100][100], int row, int col) {
    //     for (int i = 0; i < row; i++) {
    //         for (int j = 0; j < col; j++) {
    //             cout << board[i][j] << " "  ;
    //         }
    //         cout << endl;
    //     }
    // }

    bool isSafe(vector<vector<char>> &board, int row, int col, int r, int c, int num) {
        //check row
        for (int i = 0; i < row; ++i)
        {
            if (board[i][c] - '0' == num) {
                return false;
            }
        }

        //check col
        for (int i = 0; i < col; ++i)
        {
            if (board[r][i] - '0' == num) {
                return false;
            }
        }

        int rowsrart = (r / 3) * 3;
        int colstart = (c / 3) * 3;
        for (int i = rowsrart; i < rowsrart + 3; ++i)
        {
            for (int j = colstart; j < colstart + 3; ++j)
            {
                if (board[i][j] - '0' == num) {
                    return false;
                }
            }
        }

        return true;

    }

    bool SudokuSover(vector<vector<char>> &board, int row, int col, int r, int c) {
        if (r == row) {
            //display(board, row, col);
            return true;
        }
        if (c == col) {
            return SudokuSover(board, row, col, r + 1, 0);
        }

        if (board[r][c] != '.') {
            return SudokuSover(board, row, col, r, c + 1);
        }

        for (int num = 1; num <= row; num++) {
            if (isSafe(board, row, col, r, c, num)) {
                string s = to_string(num);
                board[r][c] = s[0];
                bool solveSubProblem = SudokuSover(board, row, col, r, c + 1);
                if (solveSubProblem) {
                    return true;
                } else {
                    board[r][c] = '.';
                }
            }
        }

        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        SudokuSover(board, n, n, 0, 0);
    }
};