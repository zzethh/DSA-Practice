#include<bits/stdc++.h>
using namespace std;


void display(bool board[1000][1000], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j]) {
				cout << " Q ";
			} else {
				cout << " - ";
			}
		}
		cout << endl;
	}
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


int main() {

	int r, c;
	cin >> r >> c;
	bool board[1000][1000];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] = false;
		}
	}

	int x = Nqueens(board, r, c, 0);
	cout << x;


	return 0;
}