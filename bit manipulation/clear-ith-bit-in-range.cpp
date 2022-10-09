#include<bits/stdc++.h>
using namespace std;


int getIthBit(int n, int i) {
	int mask = (1 << i);
	if (n & mask >= 1) return 1;
	else return 0;
}

void setIthBit(int &n, int i) {
	int mask = (i << i);
	n = (n | mask);
}

void clearIthBit(int &n, int i) {
	int mask = ~(1 << i);
	n = (n & mask);
}

void updateIthBit(int &n, int i, int v) {
	clearIthBit(n, i);
	int mask = (v << i);
	n = n | mask;
}

void clearLastIBits(int &n, int i) {
	int mask = (-1 << i);
	n = (n & mask);
}

void clearBitsinRange(int &n, int i, int j) {
	int a = (~0) << (j + 1);
	int b = (1 << i) - 1;
	int mask = (a | b);
	n = (n & mask);
}

void replaceBits(int &n, int m, int i, int j) {
	for (int k = i; k <= j; k++) {
		clearIthBit(n, k);
	}

	int mask = (m << i);
	n = (n | mask);
}

int main() {
	int x = 31;
	clearBitsinRange(x, 1, 3);
	cout << x;

	return 0;
}

