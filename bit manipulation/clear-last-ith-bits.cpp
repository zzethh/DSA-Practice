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

int main() {
	int x = 15;
	clearLastIBits(x, 2);
	cout << x;

	return 0;
}

