#include<bits/stdc++.h>
using namespace std;

void factorial(int n) {
	if (n == 0) {
		return;
	}
	recursion(n - 1);
	cout << n;
}

int main() {
	int n;
	cin >> n;
	factorial(n);
	return 0;
}