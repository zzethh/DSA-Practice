#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {
	static int p = 7;
	if (n == 0) {
		return 0;
	}
	//p = p - 1;
	return  ((n % 10) * pow(10, p--)) + reverseNumber(n / 10) ;
}


int main() {
	int n;
	cin >> n;
	cout << reverseNumber2(n);
	return 0;
}