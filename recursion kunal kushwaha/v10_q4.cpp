#include<bits/stdc++.h>
using namespace std;


void print_Up_Down_Obstacle(int r, int c, string s, vector<vector<bool>> maze) {
	if (r == maze.size() - 1 && c == maze[0].size() - 1) {
		cout << s << " ";
		return ;
	}

	if (maze[r][c] == 1) {
		return;
	}

	if (r < maze.size() - 1) {
		print_Up_Down_Obstacle(r + 1, c, s + 'D', maze);
	}

	if (c <  maze[0].size()) {
		print_Up_Down_Obstacle(r, c + 1, s + 'R', maze);
	}

}


int main() {
	// int r, c;
	// cin >> r >> c;
	vector<vector<bool>> v = {
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};
	string s;
	print_Up_Down_Obstacle(0, 0, s, v);
	return 0;
}