#include<bits/stdc++.h>
using namespace std;


void display(bool board[1000][1000], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j]) {
				cout << " K ";
			} else {
				cout << " - ";
			}
		}
		cout << endl;
	}
}

bool isValid(int row, int col, int r, int c) {
	if (r >= 0 && r < row && c >= 0 && c < col) {
		return true;
	}
	return false;
}

bool isSafe(bool board[1000][1000], int row, int col, int r, int c) {
	if (isValid(row, col, r - 2, c - 1)) {
		if (board[r - 2][c - 1]) {
			return false;
		}
	}

	if (isValid(row, col, r - 1, c - 2)) {
		if (board[r - 1][c - 2]) {
			return false;
		}
	}

	if (isValid(row, col, r - 2, c + 1)) {
		if (board[r - 2][c + 1]) {
			return false;
		}
	}

	if (isValid(row, col, r - 1, c + 2)) {
		if (board[r - 1][c + 2]) {
			return false;
		}
	}

	return true;

}

void Nknights(bool board[1000][1000], int row, int col, int r, int c, int knights) {
	if (knights == 0) {
		display(board, row, col);
		cout << endl;
		return ;
	}

	if (r == row) {
		return;
	}

	if (c == col) {
		Nknights(board, row, col, r + 1, 0, knights);
		return;
	}

	if (isSafe(board, row, col, r, c)) {
		board[r][c] = true;
		Nknights(board, row, col, r, c + 1, knights - 1);
		board[r][c] = false;
	}

	Nknights(board, row, col, r, c + 1, knights);
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

	Nknights(board, r, c, 0, 0, 4);




	return 0;
}