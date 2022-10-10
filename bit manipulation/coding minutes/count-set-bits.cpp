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

int countSetBits(int n) {
	int cnt = 0;
	while (n > 0) {
		int last_bit = (n & 1);
		cnt += last_bit;
		n = n >> 1;
	}
	return cnt;
}

int main() {
	int n = 15;
	cout << countSetBits(n);

	return 0;
}

