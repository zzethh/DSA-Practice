class Solution {
public:
	int topDown(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
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

	int longestCommonSubsequence(string s1, string s2) {
		int n1 = s1.length();
		int n2 = s2.length();

		vector<vector<int>> dp(n1, vector<int>(n2, -1));
		return topDown(s1, s2, 0, 0, dp);
	}
};