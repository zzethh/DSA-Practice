#include<bits/stdc++.h>
using namespace std;

int sumofdigits(int n) {
	if (n == 0) {
		return 0;
	}
	return n + sumofdigits(n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << sumofdigits(n);
	return 0;
}