#include<bits/stdc++.h>
using namespace std;


void display(int board[100][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << board[i][j] << " "  ;
		}
		cout << endl;
	}
}

bool isSafe(int board[100][100], int row, int col, int r, int c, int num) {
	//check row
	for (int i = 0; i < row; ++i)
	{
		if (board[i][c] == num) {
			return false;
		}
	}

	//check col
	for (int i = 0; i < col; ++i)
	{
		if (board[r][i] == num) {
			return false;
		}
	}

	int rowsrart = (r / 3) * 3;
	int colstart = (c / 3) * 3;
	for (int i = rowsrart; i < rowsrart + 3; ++i)
	{
		for (int j = colstart; j < colstart + 3; ++j)
		{
			if (board[i][j] == num) {
				return false;
			}
		}
	}

	return true;

}

bool SudokuSover(int board[100][100], int row, int col, int r, int c) {
	if (r == row) {
		display(board, row, col);
		return true;
	}
	if (c == col) {
		return SudokuSover(board, row, col, r + 1, 0);
	}

	if (board[r][c] != 0) {
		return SudokuSover(board, row, col, r, c + 1);
	}

	for (int num = 1; num <= row; num++) {
		if (isSafe(board, row, col, r, c, num)) {
			board[r][c] = num;
			bool solveSubProblem = SudokuSover(board, row, col, r, c + 1);
			if (solveSubProblem) {
				return true;
			} else {
				board[r][c] = 0;
			}
		}
	}

	return false;

}


int main() {
	int r, c;
	cin >> r >> c;
	int board[100][100] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	cout << SudokuSover(board, r, c, 0, 0);


	return 0;
}