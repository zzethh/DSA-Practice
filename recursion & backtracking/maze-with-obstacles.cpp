#include<bits/stdc++.h>
using namespace std;


void countingPath(int r, int c, string s, vector<vector<bool>> maze) {
	if (r == maze.size() - 1 && c == maze[0].size() - 1) {
		cout << s << " ";
		return ;
	}

	if (maze[r][c] == 1) {
		return;
	}


	if (r < maze.size() - 1) {
		countingPath(r + 1, c, s + 'D', maze);
	}

	if (c <  maze[0].size()) {
		countingPath(r, c + 1, s + 'R', maze);
	}
}


int main() {
	vector<vector<bool>> v = {
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};
	string s;
	countingPath(0, 0, s, v);
	return 0;
}