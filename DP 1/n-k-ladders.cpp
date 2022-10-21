#include<bits/stdc++.h>
using namespace std;

int countWays(int n, int k) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += countWays(n - i, k);
	}
	return sum;
}

int topDown(int n, int k, int dp[]) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	if (dp[n]) return dp[n];
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += topDown(n - i, k, dp);
	}
	return dp[n] = sum;
}

int bottomUp(int n, int k) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
			}
		}
	}
	return dp[n];
}

int main() {
	int dp[100] = {0};
	cout << countWays(4, 3);
	cout << topDown(4, 3, dp);
	cout << bottomUp(4, 3);
	return 0;
}