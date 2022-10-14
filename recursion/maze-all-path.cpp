#include<bits/stdc++.h>
using namespace std;


void allDirections(int r, int c, string s, vector<vector<bool>> &maze) {
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


int main() {
	vector<vector<bool>> v = {
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};
	string s;
	allDirections(0, 0, s, v);
	return 0;
}