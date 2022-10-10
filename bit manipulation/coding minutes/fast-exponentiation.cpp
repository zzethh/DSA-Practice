#include<bits/stdc++.h>
using namespace std;


// int getIthBit(int n, int i) {
// 	int mask = (1 << i);
// 	if (n & mask >= 1) return 1;
// 	else return 0;
// }

// void setIthBit(int &n, int i) {
// 	int mask = (i << i);
// 	n = (n | mask);
// }

// void clearIthBit(int &n, int i) {
// 	int mask = ~(1 << i);
// 	n = (n & mask);
// }

// void updateIthBit(int &n, int i, int v) {
// 	clearIthBit(n, i);
// 	int mask = (v << i);
// 	n = n | mask;
// }

// void clearLastIBits(int &n, int i) {
// 	int mask = (-1 << i);
// 	n = (n & mask);
// }

// void clearBitsinRange(int &n, int i, int j) {
// 	int a = (~0) << (j + 1);
// 	int b = (1 << i) - 1;
// 	int mask = (a | b);
// 	n = (n & mask);
// }

// void replaceBits(int &n, int m, int i, int j) {
// 	clearBitsinRange(n, i, j);

// 	int mask = (m << i);
// 	n = (n | mask);
// }

int fastExpo(int a, int n) {
	int ans = 1;
	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit) {
			ans = ans * a;
		}
		a = a * a;
		n = n >> 1;
	}

	return ans;
}

int main() {
	int n = 15;
	cout << fastExpo(2, 3);

	return 0;
}

