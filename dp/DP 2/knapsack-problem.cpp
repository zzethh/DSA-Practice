#include<bits/stdc++.h>
using namespace std;

int profit(vector<int> wts, vector<int> prices, int w, int n, int i) {
	if (i < 0) {
		return 0;
	}
	if (n == 0) {
		return 0;
	}
	int inc = -1;
	if (w - wts[i] >= 0) {
		inc = prices[i] + profit(wts, prices, w - wts[i], n - 1, i - 1);
	}
	int exc = profit(wts, prices, w, n, i - 1);
	return max(inc, exc);
}

// int topDown(string a, string b, int i, int j) {
// 	if (i == -1 and j == -1) {
// 		return 1;
// 	}
// 	if (j == -1) {
// 		return 1;
// 	}
// 	if (i == -1) {
// 		return 0;
// 	}
// 	if (a[i] == a[j]) {
// 		return topDown(a, b, i - 1, j - 1) + topDown(a, b, i - 1, j);
// 	}
// 	return topDown(a, b, i - 1, j);
// }

int bottomUp(vector<int> wts, vector<int> prices, int W, int N ) {

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for (int n = 1; n <= N; n++) {
		for (int w = 1; w <= W; w++) {
			int inc = 0, exc = 0;
			if (wts[n - 1] <= w) {
				inc = prices[n - 1] + dp[n - 1][w - wts[n - 1]];
			}
			exc = dp[n - 1][w];
			dp[n][w] = max(inc, exc);
		}
	}
	return dp[N][W];
}

int main() {
	vector<int> wts = {2, 7, 3, 4};
	vector<int> prices = {5, 20, 20, 10};

	cout << profit(wts, prices, 11, 4, 3);
	cout << bottomUp(wts, prices, 11, 4);
	return 0;
}