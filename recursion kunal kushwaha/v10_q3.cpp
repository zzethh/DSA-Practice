#include<bits/stdc++.h>
using namespace std;


void print_Up_Down_Diagonl(int r, int c, string s) {
	if (r == 1 && c == 1) {
		cout << s << " ";
		return ;
	}

	if (r > 1 && c > 1) {
		print_Up_Down_Diagonl(r - 1, c - 1, s);
	}

	if (r > 1) {
		print_Up_Down_Diagonl(r - 1, c, s + 'V');
	}

	if (c > 1) {
		print_Up_Down_Diagonl(r, c - 1, s + 'H');
	}

}


int main() {
	int r, c;
	cin >> r >> c;
	string s;
	print_Up_Down_Diagonl(r, c, s);
	return 0;
}