#include<bits/stdc++.h>
using namespace std;

int getIthBit(int n, int i) {
	int mask = (1 << i);
	if (n & mask >= 1) return 1;
	else return 0;
}

int main() {
	int x = 5;
	cout << getIthBit(5, 2);

	return 0;
}

