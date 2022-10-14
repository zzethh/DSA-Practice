#include<bits/stdc++.h>
using namespace std;


void countingPath(int r, int c, string s) {
	if (r == 1 ) {
		for (int j = 0; j < c - 1; j++) {
			s = s + 'R';
		}
		cout << s << " ";
		return;
	}

	if (c == 1) {
		for (int j = 0; j < r - 1; j++) {
			s = s + 'D';
		}
		cout << s << " ";
		return;
	}

	countingPath(r - 1, c, s + 'D');
	countingPath(r, c - 1, s + 'R');
}


int main() {
	string ans = "";
	countingPath(3, 3, ans);
	return 0;
}