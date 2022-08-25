#include<bits/stdc++.h>
using namespace std;


int count_Up_Down(int r, int c) {
	if (r == 1 || c == 1) {
		return 1;
	}

	int cnt = 0;
	cnt = cnt + count_Up_Down(r - 1, c) + count_Up_Down(r, c - 1);
	return cnt;

	//return count_Up_Down(r - 1, c) + count_Up_Down(r, c - 1);

}


int main() {
	int r, c;
	cin >> r >> c;
	cout << count_Up_Down(r, c);
	return 0;
}