class Solution {
public:
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

	int longestPalindromeSubseq(string s) {
		int n = s.length();
		//vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		string s2 = s;
		reverse(s2.begin(), s2.end());
		// return topDown(s,s2,0,0,dp);
		return bottomUp(s, s2);
	}
};