#include<bits/stdc++.h>
using namespace std;


void countingPath(int r, int c, string s) {
	if (r == 1 and c == 1) {
		cout << s << endl;
		return;
	}


	if (r > 1) countingPath(r - 1, c, s + 'D');
	if (c > 1) countingPath(r, c - 1, s + 'R');
}


int main() {
	string ans = "";
	countingPath(3, 3, ans);
	return 0;
}