#include<bits/stdc++.h>
using namespace std;

// int profit(vector<int> v) {

// }

int topDown(string a, string b, int i, int j) {
	if (i == -1 and j == -1) {
		return 1;
	}
	if (j == -1) {
		return 1;
	}
	if (i == -1) {
		return 0;
	}
	if (a[i] == a[j]) {
		return topDown(a, b, i - 1, j - 1) + topDown(a, b, i - 1, j);
	}
	return topDown(a, b, i - 1, j);
}

int bottomUp(string a, string b) {

	int m = a.length();
	int n = b.length();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[m][n];

}

int main() {
	string a = "ABCECDGCC";
	string b = "ABC";

	int dp[10][10] = {0};

	int l1 = a.length();
	int l2 = b.length();

	cout << topDown(a, b, l1 - 1, l2 - 1);
	cout << bottomUp(a, b);
	return 0;
}