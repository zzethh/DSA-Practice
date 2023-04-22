class Solution {
public:
	int topDown(vector<int> &s1, vector<int> &s2, int i, int j, vector<vector<int>> &dp) {
		if (i == s1.size() or j == s2.size()) {
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
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		vector<vector<int>> dp(n1, vector<int>(n2, -1));
		return topDown(nums1, nums2, 0, 0, dp);
	}
};