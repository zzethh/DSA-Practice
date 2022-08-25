#include<bits/stdc++.h>
using namespace std;


void printPath(int r, int c, string s, vector<vector<bool>> maze, int path[][10], int step) {
	if (r == maze.size() - 1 && c == maze[0].size() - 1) {
		path[r][c] = step;
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze[0].size(); j++) {
				cout << path[i][j] << " ";
			}
			cout << endl;
		}
		cout << s << endl << endl;
		return ;
	}

	if (maze[r][c] == 1) {
		return;
	}

	maze[r][c] = 1;
	path[r][c] = step;

	if (r < maze.size() - 1) {
		printPath(r + 1, c, s + 'D', maze, path, step + 1);
	}

	if (c <  maze[0].size() - 1) {
		printPath(r, c + 1, s + 'R', maze, path, step + 1);
	}

	if (r > 0) {
		printPath(r - 1, c , s + 'U', maze, path, step + 1);
	}

	if (c > 0) {
		printPath(r, c - 1 , s + 'L', maze, path, step + 1);
	}

	//maze[r][c] = 0;
	path[r][c] = 0;

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
	int arr[10][10] = {0};



	cout << "vector-->" << endl;
	printPath(0, 0, s, v, arr, 1);




	// cout << "array-->" << endl;
	// int m = sizeof(b) / sizeof(b[0]);
	// int n = sizeof(b[0]) / sizeof(bool);
	// allDirections2(0, 0, s, b, m, n);


	return 0;
}