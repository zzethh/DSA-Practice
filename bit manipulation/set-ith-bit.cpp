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

int main() {
	int x = 5;
	setIthBit(x, 1);
	cout << x;

	return 0;
}

