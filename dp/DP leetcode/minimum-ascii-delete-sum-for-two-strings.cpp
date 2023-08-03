class Solution {
public:
	int topDown(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
		if (i == s1.length() and j == s2.length()) {
			return 0;
		}
		if (i >= s1.length()) {
			return s2[j] + topDown(s1, s2, i, j + 1, dp);
		}
		else if (j >= s2.length()) {
			return s1[i] + topDown(s1, s2, i + 1, j, dp);
		}
		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		if (s1[i] == s2[j]) {
			return dp[i][j] = topDown(s1, s2, i + 1, j + 1, dp);
		}
		return dp[i][j] = min(s1[i] + topDown(s1, s2, i + 1, j, dp), s2[j] + topDown(s1, s2, i, j + 1, dp));
	}
	int minimumDeleteSum(string s1, string s2) {
		int n1 = s1.length();
		int n2 = s2.length();

		vector<vector<int>> dp(n1, vector<int>(n2, -1));
		return topDown(s1, s2, 0, 0, dp);
	}
};