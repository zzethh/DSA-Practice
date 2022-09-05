#include<bits/stdc++.h>
using namespace std;

int countzero(int n, int cnt) {
	if (n == 0) {
		return 0;
	}
	if (n % 10 == 0) {
		return countzero(n / 10, cnt) + 1;
	}
	return countzero(n / 10, cnt);
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	cout << countzero(n, cnt) ;
	return 0;
}