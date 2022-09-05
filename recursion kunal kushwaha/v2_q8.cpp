#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {
	static int p = floor(log10(n) + 1) - 1;
	if (n == 0) {
		return 0;
	}
	//p = p - 1;
	//cout << p << endl;
	return  ((n % 10) * pow(10, p--)) + reverseNumber(n / 10) ;
}

bool palindrome(int n) {
	if (reverseNumber(n) == n) {
		return true;
	}
	return false;
}

bool palindrome2(int arr[], int s, int e) {
	if (s > e) {
		return true;
	}

	if (arr[s] == arr[e]) {
		return palindrome2(arr, s + 1, e - 1);
	}
	return false;

}

int main() {
	int n;
	int arr[] = {1, 1, 1};
	int l = sizeof(arr) / sizeof(int);
	cin >> n;
	cout << palindrome(n) << endl;
	cout << palindrome2(arr, 0, l - 1);
	return 0;
}