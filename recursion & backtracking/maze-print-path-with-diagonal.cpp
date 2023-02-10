#include<bits/stdc++.h>
using namespace std;


void countingPath(int r, int c, string s) {
	if (r == 1 and c == 1) {
		cout << s << endl;
		return;
	}


	if (r > 1 and c > 1) countingPath(r - 1, c - 1, s + 'D');
	if (r > 1) countingPath(r - 1, c, s + 'V');
	if (c > 1) countingPath(r, c - 1, s + 'H');
}


int main() {
	string ans = "";
	countingPath(3, 3, ans);
	return 0;
}