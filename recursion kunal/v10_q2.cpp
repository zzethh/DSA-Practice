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

void print_Up_Down(int r, int c, string s) {

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

	print_Up_Down(r - 1, c, s + 'D');
	print_Up_Down(r, c - 1, s + 'R');


}

void print_Up_Down2(int r, int c, string s) {
	if (r == 1 && c == 1) {
		cout << s << " ";
		return ;
	}

	if (r > 1) {
		print_Up_Down2(r - 1, c, s + 'D');
	}

	if (c > 1) {
		print_Up_Down2(r, c - 1, s + 'U');
	}
}


int main() {
	int r, c;
	cin >> r >> c;
	string s;
	print_Up_Down2(r, c, s);
	return 0;
}