#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int i, int j) {
	if (i == s1.length() or j == s2.length()) {
		return 0;
	}

	if (s1[i] == s2[j]) {
		return 1 + LCS(s1, s2, i + 1, j + 1);
	}
	return max(LCS(s1, s2, i + 1, j), LCS(s1, s2, i, j + 1));
}

int topDown(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
	if (i == s1.length() or j == s2.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s1[i] == s2[j]) {
		return dp[i][j] = 1 + topDown(s1, s2, i + 1, j + 1, dp);
	}
	return dp[i][j] = max(topDown(s1, s2, i + 1, j, dp), topDown(s1, s2, i, j + 1, dp));
}

int bottomUp(string s1, string s2) {
	int n1 = s1.length();
	int n2 = s2.length();
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n1][n2];
}

int main() {
	string s1 = "ABCD";
	string s2 = "ABEDG";

	int n1 = s1.length();
	int n2 = s2.length();

	vector<vector<int>> dp(n1, vector<int>(n2, -1));

	cout << LCS(s1, s2, 0, 0);
	cout << topDown(s1, s2, 0, 0, dp);
	cout << bottomUp(s1, s2);
	return 0;
}