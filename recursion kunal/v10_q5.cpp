#include<bits/stdc++.h>
using namespace std;


void allDirections(int r, int c, string s, vector<vector<bool>> maze) {
	if (r == maze.size() - 1 && c == maze[0].size() - 1) {
		cout << s << endl;
		return ;
	}

	if (maze[r][c] == 1) {
		return;
	}

	maze[r][c] = 1;

	if (r < maze.size() - 1) {
		allDirections(r + 1, c, s + 'D', maze);
	}

	if (c <  maze[0].size() - 1) {
		allDirections(r, c + 1, s + 'R', maze);
	}

	if (r > 0) {
		allDirections(r - 1, c , s + 'U', maze);
	}

	if (c > 0) {
		allDirections(r, c - 1 , s + 'L', maze);
	}

	//maze[r][c] = 0;

}

void allDirections2(int r, int c, string s, bool maze[3][3], int m, int n) {
	if (r == m - 1 && c == n - 1) {
		cout << s << endl;
		return ;
	}

	if (maze[r][c] == 1) {
		return;
	}

	maze[r][c] = 1;

	if (r < m - 1) {
		allDirections2(r + 1, c, s + 'D', maze, m, n);
	}

	if (c < n - 1) {
		allDirections2(r, c + 1, s + 'R', maze, m, n);
	}

	if (r > 0) {
		allDirections2(r - 1, c , s + 'U', maze, m, n);
	}

	if (c > 0) {
		allDirections2(r, c - 1 , s + 'L', maze, m, n);
	}

	maze[r][c] = 0;

}


int main() {
	// int r, c;
	// cin >> r >> c;
	vector<vector<bool>> v = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	bool b[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	string s;
	cout << "vector-->" << endl;
	allDirections(0, 0, s, v);
	cout << endl;
	cout << "array-->" << endl;
	int m = sizeof(b) / sizeof(b[0]);
	int n = sizeof(b[0]) / sizeof(bool);
	allDirections2(0, 0, s, b, m, n);

	// cout << sizeof(b[0]) / sizeof(bool);
	return 0;
}